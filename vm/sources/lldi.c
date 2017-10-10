/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:02 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:34:24 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

void	lldi(t_battle *battle, t_command *c)
{
	t_uc	str[SIZE];
	int		i;

	i = -1;
	while (++i < 3)
		if (c->size[i] == REG_CODE && !ISREG(c->params[i]))
			return ;
		else if (i < 2 && c->type[i] == REG_CODE)
			c->params[i] = GETREGISTRE(c->params[i]);
	getmemory(battle, SETPC((c->params[0] + c->params[1])), str, SIZE);
	SETREGISTRE(c->params[2], chartoint(str, SIZE));
	CARRY = !GETREGISTRE(c->params[2]);
}
