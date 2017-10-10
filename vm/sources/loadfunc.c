/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:34:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:34:12 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define TYPEVAR(x)	((c->type[x] == REG_CODE) ? "r" : "")

void	printfunc(t_battle *battle, t_command *c)
{
	const char	*instructions[17] = {"", "live", "ld", "st", "add", "sub",
		"and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi",
		"lfor", "aff"};
	int			i;
	int			j;
	int			(*func[2])(const char*, ...);

	i = -1;
	j = !!battle->opts.ncurses;
	func[0] = ft_printf;
	func[1] = printw;
	if (battle->opts.ncurses)
	{
		mvprintw(battle->view->height, 1, "%40c", ' ');
		move(battle->view->height, 1);
	}
	func[j]("p\t%d | %s", battle->cur_process->id, instructions[c->inst]);
	while (++i < 3)
		if (c->size[i])
			func[j](" %s%d", TYPEVAR(i), c->params[i]);
	if (c->inst == ZJMP)
		func[j](" %s", (CARRY) ? "OK" : "FAILED");
	if (c->inst == LDI || c->inst == STI)
		func[j]("\n");
	func[j]("\n");
}

int		load_func(t_battle *battle)
{
	int			pc;
	t_command	command;

	pc = PC;
	command = getcommand(battle, pc);
	if (!command.error)
	{
		if (FLAG == 0)
			return (stun(battle, &command));
		FLAG = 0;
		if (battle->opts.verbose == 4)
			printfunc(battle, &command);
		battle->func[INST - 1](battle, &command);
	}
	if (command.inst == ZJMP && CARRY)
		return (0);
	return (command.len);
}
