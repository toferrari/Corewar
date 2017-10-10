/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:32:52 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:39:28 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	st(t_battle *battle, t_command *c)
{
	t_uc *str;

	if (c->size[1] == 1 && !ISREG(c->params[1]))
		return ;
	if (c->size[1] == 1 && ISREG(c->params[1]))
		c->params[1] = GETREGISTRE(c->params[1]);
	if (ISREG(c->params[0]))
	{
		c->params[0] = GETREGISTRE(c->params[0]);
		str = (t_uc*)inttochar(&c->params[0]);
		setmemory(battle, SETPC(c->params[1] % IDX_MOD), str, sizeof(int));
	}
}
