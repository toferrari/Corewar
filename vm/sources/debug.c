/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:29:06 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:38:31 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	hexa(t_uc *s, int len, int color)
{
	int i;

	i = -1;
	while (++i < len)
		if (color == -1)
			ft_printf("%.2x ", s[i]);
		else
			ft_printf("\033[4%d;%dm%.2x \033[40;0m", color, (color)
			? 30 : 0, s[i]);
}

void	debug(t_uc *s, int len)
{
	int i;

	hexa(s, 4, C_RED);
	i = 4;
	hexa(s + i, PROG_NAME_LENGTH, C_BLUE);
	i += PROG_NAME_LENGTH;
	hexa(s + i, 4, C_PURPLE);
	i += 4;
	hexa(s + i, 4, C_YELLOW);
	i += 4;
	hexa(s + i, COMMENT_LENGTH, C_GREEN);
	i += COMMENT_LENGTH;
	hexa(s + i, 4, C_PURPLE);
	i += 4;
	hexa(s + i, len - i, C_CYAN);
	ft_printf("\n");
}

void	displaybot(t_bot *bot)
{
	ft_printf("id\t\t: %x\nname\t\t: %s\ncomment\t\t: %s\ninstructions\t: %d\n",
		bot->id, bot->name, bot->comment, bot->nb_instructions);
}

void	displayprocess(t_list *elem)
{
	int			color;
	t_process	*process;

	if (!elem)
	{
		ft_printf("no elem\n");
		return ;
	}
	process = (t_process*)elem->content;
	color = -process->bot->id % 6;
	ft_printf("\033[3%dm", color);
	ft_printf("process\t: %p\npc\t: %d\nstun\t: %d\n", process,
	process->pc, process->stun);
	hexa((t_uc*)process->registre, REG_NUMBER * REG_SIZE, color);
	ft_printf("\n");
	ft_printf("\033[3%dm", color);
	displaybot(process->bot);
	ft_printf("\033[40;0m");
}
