/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:54:47 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/29 12:01:00 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_arg	*arg_create(void)
{
	t_arg	*arg;

	arg = (t_arg*)malloc(sizeof(*arg));
	if (!arg)
		show_err(0, -1);
	arg->name = NULL;
	arg->op_code = 0;
	arg->octet = 0;
	arg->special = 0;
	arg->ref = NULL;
	arg->next = NULL;
	arg->prec = NULL;
	arg->tot_octets = 0;
	return (arg);
}

void	arg_delete(t_arg **head)
{
	t_arg	*lst;
	t_arg	*next;

	lst = *head;
	while (lst)
	{
		next = lst->next;
		if (lst->name)
		{
			free(lst->name);
			lst->name = NULL;
		}
		free(lst);
		lst = next;
	}
	*head = NULL;
}

void	arg_add(t_arg **head, t_arg *arg)
{
	t_arg	*lst;

	lst = *head;
	if (!lst)
		*head = arg;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = arg;
		arg->prec = lst;
	}
}
