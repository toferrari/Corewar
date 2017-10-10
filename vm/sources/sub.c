/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:14 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/26 18:22:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sub(t_battle *battle, t_command *c)
{
	if (ISREG(c->params[0]) && ISREG(c->params[1]) && ISREG(c->params[2]))
	{
		SETREGISTRE(c->params[2],
			GETREGISTRE(c->params[1]) - GETREGISTRE(c->params[0]));
		CARRY = !GETREGISTRE(c->params[2]);
	}
}
