/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmemory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:53:41 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/26 18:06:52 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	totalsize(t_bots bots)
{
	int i;
	int total;

	i = -1;
	total = 0;
	while (++i < bots.nb)
		total += bots.tab[i]->nb_instructions;
	return (total);
}

t_list		*addprocess(t_list **list, t_process process)
{
	t_list		*tmp;

	if (!(tmp = ft_lstnew(&process, sizeof(process))))
		return (NULL);
	if (!*list)
		*list = tmp;
	else
		ft_lstadd(list, tmp);
	return (*list);
}

t_list		*loadmemory(t_battle *b)
{
	int		i;
	int		j;
	int		space;
	int		index_bot;
	t_list	*list;

	if (!b || !b->bots.nb)
		return (NULL);
	i = -1;
	j = 0;
	list = NULL;
	space = (MEM_SIZE - totalsize(b->bots)) / b->bots.nb;
	bzero(b->memory, MEM_SIZE);
	while (++i < b->bots.nb)
	{
		index_bot = (j + i * space);
		if (!addprocess(&list, newprocess(b->bots.tab[i], index_bot)))
			return (NULL);
		b->cur_process = (t_process*)list->content;
		setmemory(b, index_bot,
			b->bots.tab[i]->instructions, b->bots.tab[i]->nb_instructions);
		j += b->bots.tab[i]->nb_instructions;
	}
	return (list);
}
