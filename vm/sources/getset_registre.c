/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_registre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:48:20 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/26 18:12:34 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	set_registre(t_process *process, int i, int value)
{
	process->registre[i] = value;
	process->last_action[2] = i;
}

int		get_registre(t_process *process, int i)
{
	return (process->registre[i]);
}
