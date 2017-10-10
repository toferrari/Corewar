/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showview.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:32:30 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:40:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

void	setvcolor(t_battle *battle, int index, int color, int len)
{
	int i;

	i = -1;
	while (++i < len)
		VCOLOR[mod(index + i, MEM_SIZE)] = color;
}

void	showmemory(t_battle *battle)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	ft_memcpy(VCOLOR, battle->print_mem, MEM_SIZE);
	ft_color_mem(battle);
	tmp = ft_strhexa((t_uc*)battle->memory, MEM_SIZE);
	len = ft_strlen(tmp);
	wmove(VIEWMEM, 1, 2);
	while (i < len)
	{
		wattron(VIEWMEM, COLOR_PAIR(
			(!VCOLOR[i / 3]) ? COLOR_NOT : VCOLOR[i / 3]));
		if (!(i % (COL1_W - 3)))
			wmove(VIEWMEM, (1 + i / (COL1_W - 3)), 2);
		waddnstr(VIEWMEM, tmp + i, 3);
		i += 3;
	}
	wrefresh(VIEWMEM);
	ft_strdel(&tmp);
}

void	showallview(t_battle *battle)
{
	if (!battle->view)
		return ;
	showbot(battle);
	showmemory(battle);
	wattron(battle->view->windows[1], COLOR_PAIR(100));
	box(battle->view->windows[1], ACS_VLINE, ACS_HLINE);
	mvprintw(0, 10, " Speed : %d/s    Total cycle : %6d Cycle : "
		"%4d    Limit : %4d    Check : %4d ",
		battle->view->speed, battle->fight.totalcycle, battle->fight.cycle,
		battle->fight.cycle_to_die, battle->fight.checks);
	mvprintw(0, COL2_X + 10, " Dernier joueur rapporte vivant : %s ",
		(battle->fight.last_live) ? battle->fight.last_live->name : "");
	controls(battle);
	if (battle->view->speed < 500)
		usleep(SECONDS / battle->view->speed);
}
