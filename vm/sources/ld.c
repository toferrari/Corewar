/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:34:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:34:33 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ld(t_battle *battle, t_command *c)
{
	if (ISREG(c->params[1]))
	{
		SETREGISTRE(c->params[1], c->params[0]);
		CARRY = !GETREGISTRE(c->params[1]);
	}
}
