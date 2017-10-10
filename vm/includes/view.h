/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:40:31 by dbischof          #+#    #+#             */
/*   Updated: 2017/08/01 15:45:55 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "vm.h"
# include <ncurses.h>

# define SECONDS	1000000

# define HEIGHT		(64 + 2)
# define WIDTH		(192 + 110)

# define COL1_X		0
# define COL1_Y		0
# define COL1_W		(192 + 3)
# define COL1_H		(HEIGHT)

# define COL2_X		(COL1_X + COL1_W)
# define COL2_W		(WIDTH - COL2_X)
# define COL2_H		(HEIGHT / 4)
# define COL2_Y		((i - 1) * COL2_H)

# define NBOTS		battle->bots.nb
# define VIEWMEM	battle->view->windows[0]
# define VCOLOR		battle->view->memcolor
# define COLOR_NOT	100

enum{NOT,
	BLUE_BACK, GREEN_BACK, RED_BACK, YELLOW_BACK,
	BLUE_PC, GREEN_PC, RED_PC, YELLOW_PC,
	BLUE_LAST, GREEN_LAST, RED_LAST, YELLOW_LAST
};

typedef struct s_battle	t_battle;

typedef struct	s_view {
	WINDOW		**windows;
	int			width;
	int			height;
	char		*memcolor;
	int			speed;
	int			pause;
	int			screendown;
}				t_view;

t_view			*initview(t_battle *battle);
void			viewfinnish(t_battle *battle);
void			showallview(t_battle *battle);
void			ft_color_mem(t_battle *battle);
void			color_pc(t_battle *battle);
void			showbot(t_battle *battle);
void			controls(t_battle *battle);
void			refreshall(t_battle *battle);
void			setvcolor(t_battle *battle, int index, int color, int len);

#endif
