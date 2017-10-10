/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:00:54 by dbischof          #+#    #+#             */
/*   Updated: 2017/08/21 15:14:29 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define BUFFER		10000
#define NB_MAG		(0)
#define NAME		(4)
#define OC_NULL_1	(4 + PROG_NAME_LENGTH)
#define NB_INST		(8 + PROG_NAME_LENGTH)
#define COMMENT		(12 + PROG_NAME_LENGTH)
#define OC_NULL_2	(12 + PROG_NAME_LENGTH + COMMENT_LENGTH)
#define INSTA		(16 + PROG_NAME_LENGTH + COMMENT_LENGTH)
#define MIN_BOT		INSTA + 1
#define ERR_BOT		(1<<0)
#define ERR_MAG		(1<<1)
#define ERR_OC1		(1<<2)
#define ERR_OC2		(1<<3)
#define ERR_INT		(1<<4)
#define ERR_SIZ		(1<<5)
#define ERR_LEN		(1<<6)
#define NB_ERR		7

int		open_bot(char *path, unsigned char **bot)
{
	int		fd;
	int		ret;
	char	buff[BUFFER];

	ret = 0;
	ft_bzero(buff, BUFFER);
	if ((fd = open(path, O_RDONLY)) != -1)
		if ((ret = read(fd, buff, BUFFER)) != -1)
		{
			*bot = (unsigned char*)malloc(ret);
			ft_memcpy(*bot, buff, ret);
			return (ret);
		}
	return (ret);
}

int		check_error(unsigned char *bot, int len)
{
	int error;

	if (!bot)
		return (ERR_BOT);
	if (len < MIN_BOT)
		return (ERR_LEN);
	error = 0;
	error |= (chartoint(bot + NB_MAG, 4) == COREWAR_EXEC_MAGIC) ? 0 : ERR_MAG;
	error |= (!chartoint(bot + OC_NULL_1, 4)) ? 0 : ERR_OC1;
	error |= (!chartoint(bot + OC_NULL_2, 4)) ? 0 : ERR_OC2;
	error |= (chartoint(bot + NB_INST, 4) == len - INSTA) ? 0 : ERR_INT;
	error |= (chartoint(bot + NB_INST, 4) <= CHAMP_MAX_SIZE) ? 0 : ERR_SIZ;
	return (error);
}

int		print_error(int err)
{
	static char	*error[NB_ERR] = {
		"no bot",
		"num magic",
		"octet null 1",
		"octet null 2",
		"num instructions",
		"size max",
		"size min"
	};
	int			i;
	int			tmp;

	i = -1;
	tmp = err;
	while (++i < NB_ERR)
	{
		if (i && tmp & 1)
			ft_printf("error: %s\n", error[i]);
		tmp >>= 1;
	}
	return (err);
}

t_bot	*newbot(void)
{
	t_bot *bot;

	bot = (t_bot*)malloc(sizeof(t_bot));
	bot->name = ft_strnew(PROG_NAME_LENGTH);
	bot->comment = ft_strnew(COMMENT_LENGTH);
	bot->instructions = NULL;
	bot->nb_instructions = 0;
	return (bot);
}

t_bot	*creabot(char *path)
{
	int				length;
	t_bot			*bot;
	unsigned char	*bot_brut;

	bot_brut = NULL;
	length = open_bot(path, &bot_brut);
	if (print_error(check_error(bot_brut, length)))
		return (NULL);
	bot = newbot();
	ft_memcpy(bot->name, (bot_brut + NAME), PROG_NAME_LENGTH);
	bot->nb_instructions = chartoint(bot_brut + NB_INST, 4);
	ft_memcpy(bot->comment, (bot_brut + COMMENT), COMMENT_LENGTH);
	bot->instructions = (unsigned char*)malloc(bot->nb_instructions);
	ft_memcpy(bot->instructions, (bot_brut + INSTA), bot->nb_instructions);
	bot->nbprocess = 0;
	ft_memdel((void**)&bot_brut);
	return (bot);
}
