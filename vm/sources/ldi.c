/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:43:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 16:08:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define SIZE sizeof(int)

void	ldi(t_battle *battle, t_command *c)
{
	t_uc	str[SIZE];
	int		i;

	i = -1;
	while (++i < 3)
		if (c->size[i] == REG_CODE && !ISREG(c->params[i]))
			return ;
		else if (i < 2 && c->type[i] == REG_CODE)
			c->params[i] = GETREGISTRE(c->params[i]);
	getmemory(battle, SETPC((c->params[0] + c->params[1]) % IDX_MOD),
	str, SIZE);
	SETREGISTRE(c->params[2], chartoint(str, SIZE));
}
