/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:33:30 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:33:32 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

void	init_color_view(void)
{
	curs_set(0);
	init_color(COLOR_WHITE, 700, 700, 700);
	init_pair(100, COLOR_WHITE, COLOR_BLACK);
	init_pair(BLUE_BACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(BLUE_PC, COLOR_BLACK, COLOR_BLUE);
	init_pair(BLUE_LAST, COLOR_WHITE, COLOR_BLUE);
	init_pair(GREEN_BACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(GREEN_PC, COLOR_BLACK, COLOR_GREEN);
	init_pair(GREEN_LAST, COLOR_WHITE, COLOR_GREEN);
	init_pair(RED_BACK, COLOR_RED, COLOR_BLACK);
	init_pair(RED_PC, COLOR_BLACK, COLOR_RED);
	init_pair(RED_LAST, COLOR_WHITE, COLOR_RED);
	init_pair(YELLOW_BACK, COLOR_YELLOW, COLOR_BLACK);
	init_pair(YELLOW_PC, COLOR_BLACK, COLOR_YELLOW);
	init_pair(YELLOW_LAST, COLOR_WHITE, COLOR_YELLOW);
}

void	initparamsview(t_battle *battle, t_view *view)
{
	int		i;

	i = -1;
	view->width = WIDTH;
	view->height = HEIGHT;
	view->memcolor = ft_strnew(MEM_SIZE);
	view->speed = 50;
	view->pause = 1;
	view->screendown = 0;
	while (++i < 1 + NBOTS)
	{
		view->windows[i] = (!i)
			? subwin(stdscr, COL1_H, COL1_W, COL1_Y, COL1_X)
			: subwin(stdscr, COL2_H, COL2_W, COL2_Y, COL2_X);
		box(view->windows[i], ACS_VLINE, ACS_HLINE);
	}
}

void	refreshall(t_battle *battle)
{
	int		i;

	i = -1;
	clear();
	while (++i < 1 + NBOTS)
	{
		battle->view->windows[i] = (!i)
			? subwin(stdscr, COL1_H, COL1_W, COL1_Y, COL1_X)
			: subwin(stdscr, COL2_H, COL2_W, COL2_Y, COL2_X);
		box(battle->view->windows[i], ACS_VLINE, ACS_HLINE);
		wrefresh(battle->view->windows[i]);
	}
	refresh();
}

t_view	*initview(t_battle *battle)
{
	t_view	*view;

	if (!(view = (t_view*)malloc(sizeof(t_view)))
		|| !(view->windows = (WINDOW**)malloc(sizeof(WINDOW*) * NBOTS)))
		return (NULL);
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	if (has_colors())
	{
		start_color();
		init_color_view();
	}
	initparamsview(battle, view);
	return (view);
}

void	viewfinnish(t_battle *battle)
{
	int i;

	i = -1;
	if (!battle->view)
		return ;
	nodelay(stdscr, FALSE);
	if (battle->fight.last_live)
	{
		mvprintw(0, COL2_X + 10, " Le joueur %d(%s) a gagne\n ",
			battle->fight.last_live->id, battle->fight.last_live->name);
		getch();
	}
	curs_set(1);
	endwin();
	free(VCOLOR);
	while (++i < NBOTS)
		free(battle->view->windows[i]);
	free(battle->view);
}
