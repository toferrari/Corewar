/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:11 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:39:35 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sti(t_battle *battle, t_command *c)
{
	t_uc	*str;
	int		i;

	i = -1;
	while (++i < 3)
		if (c->size[i] == T_REG && !ISREG(c->params[i]))
			return ;
		else if (c->size[i] == T_REG)
			c->params[i] = GETREGISTRE(c->params[i]);
	str = (t_uc*)inttochar(&c->params[0]);
	setmemory(battle, SETPC(c->params[1] + c->params[2]), str, sizeof(int));
}
