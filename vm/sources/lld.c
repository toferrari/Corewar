/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:39:26 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/26 18:08:30 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lld(t_battle *battle, t_command *c)
{
	if (ISREG(c->params[1]))
	{
		SETREGISTRE(c->params[1], c->params[0]);
		CARRY = !GETREGISTRE(c->params[1]);
	}
}
