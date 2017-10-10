/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:33:53 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/30 16:51:38 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*give_line(char *str)
{
	int		space;
	int		comment;
	int		str_len;
	int		dst_len;
	char	*dst;

	space = 0;
	comment = cor_strchr(str, '#');
	str_len = ft_strlen(str);
	while (str[space] && ft_is_space(str[space]))
		space++;
	dst_len = (comment != -1) ? (comment - space) : (str_len - space);
	if (dst_len != str_len)
	{
		dst = ft_strnew(dst_len);
		ft_strncpy(dst, &str[space], dst_len);
		return (dst);
	}
	return (ft_strdup(str));
}

static void	fill_parsing(t_asm *env, t_file *file)
{
	int		i;
	char	str[BUF_SZ];

	i = 0;
	while (my_fgets(str, BUF_SZ, file))
		env->nb_line++;
	lseek(file->fd, 0, SEEK_SET);
	env->str = (char**)malloc(sizeof(char*) * env->nb_line);
	if (!env->str)
		show_err(0, -1);
	while (my_fgets(str, BUF_SZ, file))
	{
		env->str[i] = give_line(str);
		i++;
	}
}

static void	parse_header(t_asm *env)
{
	env->i = 0;
	env->header_len = 0;
	while (env->i < env->nb_line
		&& (!env->prog_name[0] || !env->comment[0]))
	{
		if (!env->str[env->i][0])
			;
		else if (!env->prog_name[0] && !ft_strncmp(env->str[env->i],
			NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			copy_header(env->prog_name, env,
				ft_strlen(NAME_CMD_STRING), 1);
		else if (!env->comment[0] && !ft_strncmp(env->str[env->i],
			COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			copy_header(env->comment, env,
				ft_strlen(COMMENT_CMD_STRING), 2);
		else
			show_err2(7, env->i);
		env->i++;
		env->header_len++;
	}
	if (!env->prog_name[0] || !env->comment[0])
		show_err(7, 0);
}

int			parsing_asm(t_asm *env, t_file *file)
{
	char		str[BUF_SZ];

	env->nb_line = 0;
	ft_bzero(str, BUF_SZ);
	fill_parsing(env, file);
	parse_header(env);
	parse_instruction(env);
	label_exist(env);
	good_order(env);
	return (0);
}
