/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:15 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/29 10:39:13 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label2(t_arg *lst, int fd, int line, t_asm *env)
{
	int		i;
	t_arg	*find;

	i = 0;
	find = env->args;
	while (find)
	{
		if (find->special & T_INSTRU)
			i++;
		else
		{
			if (find && i == line && !(find->special & T_LAB) &&
				ft_strcmp(&(find->name[1]), &(lst->name[1])) == 0)
				return (write_translation(label_apres(find, lst), 2, fd));
			else if (find && ft_strcmp(find->name, &(lst->name[1])) == 0 &&
				(find->special & T_LAB))
				return (write_translation(label_avant(find, lst, i, line),
					2, fd));
		}
		find = find->next;
	}
}

void	label4(t_arg *lst, int fd, int line, t_asm *env)
{
	int		i;
	t_arg	*find;

	i = 0;
	find = env->args;
	while (find)
	{
		if (find->special & T_INSTRU)
			i++;
		else
		{
			if (find && i == line && !(find->special & T_LAB)
				&& ft_strcmp(&(find->name[1]), &(lst->name[1])) == 0)
				return (write_translation(label_apres(find, lst), 4, fd));
			else if (find && ft_strcmp(find->name, &(lst->name[1])) == 0
				&& (find->special & T_LAB))
				return (write_translation(label_avant(find, lst, i, line),
					4, fd));
		}
		find = find->next;
	}
}

void	on_4oct(t_arg *lst, int fd, int line, t_asm *env)
{
	unsigned int	nb;

	if (lst->name[0] == ':')
		label4(lst, fd, line, env);
	else
	{
		nb = ft_atoi(lst->name);
		write_translation(nb, 4, fd);
	}
}

void	on_2oct(t_arg *lst, int fd, int line, t_asm *env)
{
	unsigned int	nb;

	if (lst->name[0] == ':')
		label2(lst, fd, line, env);
	else
	{
		nb = ft_atoi(lst->name);
		write_translation(nb, 2, fd);
	}
}

void	write_dir(t_arg *lst, int fd, int line, t_asm *env)
{
	if (lst->octet == 4)
		on_4oct(lst, fd, line, env);
	else
		on_2oct(lst, fd, line, env);
}
