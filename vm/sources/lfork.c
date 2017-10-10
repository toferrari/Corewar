/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:13:18 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/26 18:10:11 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lfork(t_battle *battle, t_command *c)
{
	addprocess(&battle->process, cpyprocess(battle->cur_process,
	SETPC(c->params[0])));
}
