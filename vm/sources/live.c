/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:30:28 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:30:32 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	live(t_battle *battle, t_command *c)
{
	int i;

	i = -1;
	while (++i < battle->bots.nb)
	{
		if (battle->bots.tab[i]->id == c->params[0])
		{
			battle->cur_process->live++;
			battle->fight.last_live = battle->bots.tab[i];
		}
	}
}
