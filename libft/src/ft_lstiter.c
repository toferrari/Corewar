/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:50:09 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/01 15:11:18 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*to_iter;

	to_iter = lst;
	while (to_iter)
	{
		f(to_iter);
		to_iter = to_iter->next;
	}
}
