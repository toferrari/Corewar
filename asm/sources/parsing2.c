/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:42 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/12 09:17:47 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_len(int len, int line, int id)
{
	if (id == 1 && len > PROG_NAME_LENGTH)
	{
		ft_putstr_fd("Name lenght too big: line ", 2);
		ft_putnbr_fd(line + 1, 2);
		ft_putendl_fd(".", 2);
		exit(EXIT_FAILURE);
	}
	else if (id == 2 && len > COMMENT_LENGTH)
	{
		ft_putstr_fd("Comment lenght too big: line ", 2);
		ft_putnbr_fd(line + 1, 2);
		ft_putendl_fd(".", 2);
		exit(EXIT_FAILURE);
	}
}

int			verif_exist(t_arg *lst, t_arg *label)
{
	while (lst)
	{
		if ((lst->special & T_LAB) &&
			ft_strcmp(lst->name, &(label->name[1])) == 0)
			return (1);
		lst = lst->next;
	}
	show_err(4, label->line);
	return (0);
}

void		label_exist(t_asm *env)
{
	t_arg	*lst;
	t_arg	*tmp;
	int		line;

	line = env->header_len;
	lst = env->args;
	tmp = env->args;
	while (lst)
	{
		if (!(lst->special & T_LAB) && ft_strchr(lst->name, LABEL_CHAR))
			verif_exist(tmp, lst);
		lst = lst->next;
	}
}

void		copy_header(char *dst, t_asm *env, int i, int id)
{
	int	j;
	int k;

	j = 0;
	k = 0;
	while (ft_is_space(env->str[env->i][i]))
		i++;
	if (env->str[env->i][i] != '"')
		show_err(3, env->i);
	i++;
	while (env->str[env->i][i] != '"')
	{
		k++;
		dst[j++] = env->str[env->i][i++];
	}
	check_len(k, env->i, id);
	i++;
	while (ft_is_space(env->str[env->i][i]))
		i++;
	if (env->str[env->i][i])
		show_err(3, env->i);
}

void		parse_instruction(t_asm *env)
{
	int		n_args;
	t_arg	*ref_inst;

	ref_inst = NULL;
	while (env->i < env->nb_line)
	{
		env->oct_line = 0;
		if (env->str[env->i][0])
		{
			find_lab(env);
			if ((n_args = find_ins(env, &ref_inst)) != 0)
				find_par(env, n_args, ref_inst);
		}
		env->i++;
	}
}
