/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcommand2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:29:40 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:29:43 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define OCP			battle->memory[pc + 1]
#define PARAMS		battle->memory[(pc + ((c->isocp) ? 2 : 1))]
#define PARAM(n)	(OCP >> ((3 - n) * 2) & 0b11)

int		isocp(char inst)
{
	return (inst == LD || inst == ST || inst == ADD || inst == SUB
		|| inst == AND || inst == OR || inst == XOR || inst == LDI
		|| inst == STI || inst == LLD || inst == LLDI);
}

int		t_ind_size(t_battle *battle, char inst, int i, int pc)
{
	if ((inst == LD || inst == AND || inst == OR || inst == XOR ||
	inst == LLD) && PARAM(i) == T_DIR)
		return (4);
	else
		return (PARAM(i));
}

void	size_p(t_battle *battle, t_command *c, int pc)
{
	int i;

	i = -1;
	if (c->inst == AFF)
		c->size[0] = 1;
	else if (c->inst == LIVE)
		c->size[0] = 4;
	else if (c->inst == ZJMP || c->inst == FORK || c->inst == LFORK)
		c->size[0] = 2;
	else
		while (++i < 3)
			c->size[i] = (PARAM(i) != 3) ?
			t_ind_size(battle, c->inst, i, pc) : 2;
}
