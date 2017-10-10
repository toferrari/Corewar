/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:29:54 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:39:07 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			mod(int a, int b)
{
	int ret;

	if (b < 0)
		return (mod(a, -b));
	ret = a % b;
	if (ret < 0)
		ret += b;
	return (ret);
}

int			setmemory(t_battle *battle, int index, t_uc *s, int len)
{
	int i;

	i = -1;
	if (!battle || !s || len <= 0 || MEM_SIZE <= 0)
		return (0);
	while (++i < len)
	{
		battle->memory[mod(index + i, MEM_SIZE)] = s[i];
		battle->print_mem[mod(index + i, MEM_SIZE)] =
			(char)(1 + battle->cur_process->bot->rid);
	}
	battle->cur_process->last_action[0] = index;
	battle->cur_process->last_action[1] = len;
	return (1);
}

t_uc		*getmemory(t_battle *battle, int index, t_uc *buff, int len)
{
	int i;

	i = -1;
	if (!battle || !buff || len <= 0 || MEM_SIZE <= 0)
		return (buff);
	while (++i < len)
		buff[i] = battle->memory[mod(index + i, MEM_SIZE)];
	return (buff);
}
