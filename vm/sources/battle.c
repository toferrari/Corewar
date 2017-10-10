/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:27:13 by tferrari          #+#    #+#             */
/*   Updated: 2017/09/20 17:48:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define PROCESS	((t_process*)elem->content)

int			verif_live(t_battle *battle)
{
	int			total;
	t_list		*elem;
	t_process	*process;

	total = 0;
	elem = battle->process;
	while (elem)
	{
		process = PROCESS;
		if (!process->dead)
		{
			total += process->live;
			if (!process->live && !process->dead)
			{
				total--;
				process->bot->nbprocess--;
				process->dead = 1;
			}
			process->live = 0;
		}
		elem = elem->next;
	}
	return (total);
}

int			rulescycle(t_battle *battle)
{
	int			live;

	if (OPTS.dump)
		OPTS.n_dump--;
	if (OPTS.dump && OPTS.n_dump <= 0)
		return (0);
	if (battle->fight.cycle >= battle->fight.cycle_to_die)
	{
		if (battle->fight.totalcycle > battle->fight.cycle_to_die)
		{
			if (!(live = verif_live(battle)))
				return (0);
			if (live >= NBR_LIVE)
				battle->fight.cycle_to_die -= CYCLE_DELTA;
			if (battle->fight.checks >= MAX_CHECKS)
			{
				battle->fight.checks = 0;
				battle->fight.cycle_to_die--;
			}
			battle->fight.checks++;
		}
		battle->fight.cycle = 0;
	}
	return (1);
}

void		battle_launch(t_battle *battle)
{
	t_list		*elem;
	int			tmp;

	while (rulescycle(battle))
	{
		elem = battle->process;
		while (elem)
		{
			if (PROCESS->stun > 0)
				PROCESS->stun--;
			if (!PROCESS->dead && !PROCESS->stun)
			{
				battle->cur_process = PROCESS;
				tmp = load_func(battle);
				PC = SETPC(tmp);
			}
			elem = elem->next;
		}
		battle->fight.cycle++;
		battle->fight.totalcycle++;
		showallview(battle);
	}
	return ;
}

void		initbattle_func(t_battle *battle)
{
	battle->func[0] = live;
	battle->func[1] = ld;
	battle->func[2] = st;
	battle->func[3] = add;
	battle->func[4] = sub;
	battle->func[5] = and_ft;
	battle->func[6] = or_ft;
	battle->func[7] = xor_ft;
	battle->func[8] = zjmp;
	battle->func[9] = ldi;
	battle->func[10] = sti;
	battle->func[11] = fork_ft;
	battle->func[12] = lld;
	battle->func[13] = lldi;
	battle->func[14] = lfork;
	battle->func[15] = aff;
}

t_battle	*initbattle(int ac, char **av, char **en)
{
	t_battle	*b;

	if (!(b = malloc(sizeof(t_battle))))
		return (NULL);
	b->env = en;
	b->bots = loadbots(ac, av);
	if (!(b->process = loadmemory(b)))
		return (NULL);
	b->view = NULL;
	b->fight.cycle = 0;
	b->fight.totalcycle = 0;
	b->fight.checks = 0;
	b->fight.cycle_to_die = CYCLE_TO_DIE;
	b->fight.last_live = NULL;
	b->opts.ncurses = 0;
	b->opts.verbose = 0;
	initbattle_func(b);
	ft_bzero(&b->opts, sizeof(b->opts));
	return (b);
}
