/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:21:41 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 14:42:31 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	fork_ft(t_battle *battle, t_command *c)
{
	addprocess(&battle->process, cpyprocess(battle->cur_process,
		SETPC(c->params[0] % IDX_MOD)));
}
