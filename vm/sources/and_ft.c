/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:27:04 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:27:07 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	and_ft(t_battle *battle, t_command *c)
{
	int i;

	i = -1;
	while (++i < 3)
		if (c->size[i] == 1 && !ISREG(c->params[i]))
			return ;
		else if (i < 2 && c->type[i] == REG_CODE)
			c->params[i] = GETREGISTRE(c->params[i]);
	SETREGISTRE(c->params[2], c->params[0] & c->params[1]);
	CARRY = !GETREGISTRE(c->params[2]);
}
