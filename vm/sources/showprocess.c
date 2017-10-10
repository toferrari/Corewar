/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:44:30 by dbischof          #+#    #+#             */
/*   Updated: 2017/08/01 15:40:31 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

void	ft_color_mem(t_battle *battle)
{
	t_list		*elem;
	t_process	*pr;
	int			colorbase;

	elem = battle->process;
	while (elem)
	{
		pr = (t_process*)elem->content;
		if (!pr->dead)
		{
			colorbase = (1 + pr->bot->rid) % 4;
			if (pr->last_action[0] != -1 && pr->last_action[1] != -1)
				setvcolor(battle, pr->last_action[0], colorbase + 8,
				pr->last_action[1]);
			VCOLOR[pr->pc] = (colorbase + 4);
		}
		elem = elem->next;
	}
}

void	showparam(WINDOW *win, int size, int param)
{
	if (size == 1)
		wprintw(win, "%-8d\t", param);
	else if (size == 2)
		wprintw(win, "%-8d\t", param);
	else if (size == 4)
		wprintw(win, "%-8d\t", param);
	else
		wprintw(win, "%-8s\t", "--");
}

void	showprocess(t_battle *battle, WINDOW *win, t_process *process, int posy)
{
	const char	*instructions[17] = {"", "LIVE", "LD", "ST", "ADD", "SUB",
		"AND", "OR", "XOR", "ZJMP", "LDI", "STI", "FORK", "LLD", "LLDI",
		"LFOR", "AFF"};
	char		tmp[10];
	char		*tmp2;
	t_command	c;
	int			i;

	i = -1;
	c = getcommand(battle, process->pc);
	ft_bzero(tmp, 10);
	getmemory(battle, process->pc, (t_uc*)tmp, 2);
	tmp2 = ft_strhexa((t_uc*)tmp, 10);
	mvwprintw(win, posy, 1, "%-3c%.2x\t%-4s\t",
		((process->carry) ? 'v' : 'x'), c.inst,
		((c.error) ? "" : instructions[c.inst]));
	while (++i < 3)
		showparam(win, c.size[i], c.params[i]);
	wprintw(win, "%4d\t%4d\t%4d\t",
		c.len, process->stun, process->live);
	wprintw(win, "%d ", 1 + process->last_action[2]);
	if (process->last_action[2] >= 0 && process->last_action[2] < REG_NUMBER)
		wprintw(win, "%.8x", process->registre[process->last_action[2]]);
	free(tmp2);
}

void	shearchprocess(t_battle *battle, WINDOW *win, t_bot *bot)
{
	int			posy;
	t_list		*elem;
	t_process	*process;

	elem = battle->process;
	posy = 6;
	while (elem && posy < 15)
	{
		process = (t_process*)elem->content;
		if (process->bot == bot && !process->dead)
			showprocess(battle, win, process, posy++);
		elem = elem->next;
	}
	wrefresh(win);
}

void	showbot(t_battle *battle)
{
	int		i;
	WINDOW	*win;
	t_bot	*bot;

	i = 0;
	while (++i < NBOTS + 1)
	{
		win = battle->view->windows[i];
		bot = battle->bots.tab[i - 1];
		wattron(win, COLOR_PAIR(i));
		mvwprintw(win, 1, 1, "Nom\t\t: %s (%d)", bot->name, bot->id);
		mvwprintw(win, 2, 1, "Description\t: %s", bot->comment);
		mvwprintw(win, 4, 1, "%-3d Processus\t:", bot->nbprocess);
		mvwprintw(win, 5, 4,
			"PC\tINST\tPARAM1\t\tPARAM2\t\tPARAM3\t\tSAUT\tSTUN\tLIVE\tMEMORY");
		shearchprocess(battle, win, bot);
		wrefresh(win);
	}
}
