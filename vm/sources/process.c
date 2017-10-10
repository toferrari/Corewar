/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:02:24 by dbischof          #+#    #+#             */
/*   Updated: 2017/08/01 15:26:34 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			getid(void)
{
	static int id = 0;

	return (++id);
}

t_process	newprocess(t_bot *bot, int pc)
{
	t_process process;

	process.pc = pc;
	process.bot = bot;
	process.id = getid();
	process.stun = 0;
	process.dead = 0;
	process.live = 0;
	process.carry = 0;
	ft_bzero(process.registre, REG_NUMBER * REG_SIZE);
	process.registre[0] = bot->id;
	process.flag = 0;
	process.last_action[0] = -1;
	process.last_action[1] = -1;
	process.last_action[2] = -1;
	process.bot->nbprocess++;
	return (process);
}

t_process	cpyprocess(t_process *orignal, int pc)
{
	t_process process;

	process.pc = pc;
	process.bot = orignal->bot;
	process.id = getid();
	process.stun = 0;
	process.dead = 0;
	process.live = 0;
	process.carry = orignal->carry;
	ft_memcpy(process.registre, orignal->registre, REG_NUMBER * REG_SIZE);
	process.flag = 0;
	process.last_action[0] = -1;
	process.last_action[1] = -1;
	process.last_action[2] = -1;
	process.bot->nbprocess++;
	return (process);
}
