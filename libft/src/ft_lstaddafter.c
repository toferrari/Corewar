/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddafter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:54:37 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/23 11:55:32 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddafter(t_list **alst, t_list *node_new)
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp == NULL)
	{
		ft_lstadd(alst, node_new);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node_new;
}
