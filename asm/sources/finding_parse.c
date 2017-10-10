/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:30 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/09 10:54:06 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		type_par(char *str, t_asm *env, t_arg *ref_inst)
{
	t_arg	*arg;

	arg = arg_create();
	if (str[0] == 'r')
	{
		arg->special |= T_REG;
		arg->octet = 1;
		arg->name = ft_strsub(str, 0, new_strlen(str));
	}
	else if (str[0] == '%')
	{
		arg->special |= T_DIR;
		arg->octet = nb_octet(env);
		arg->name = ft_strsub(str, 1, new_strlen(str) - 1);
	}
	else
	{
		arg->special |= T_IND;
		arg->octet = 2;
		arg->name = ft_strsub(str, 0, new_strlen(str));
	}
	arg->line = env->i;
	verif_name(env, arg);
	ref_inst->tot_octets += arg->octet;
	arg_add(&env->args, arg);
}

void			find_lab(t_asm *env)
{
	t_arg	*arg;

	env->j = 0;
	while (!ft_is_space(env->str[env->i][env->j]) &&
		env->str[env->i][env->j] != LABEL_CHAR)
	{
		if (!is_in(LABEL_CHARS, env->str[env->i][env->j]))
			show_err(3, env->i);
		env->j++;
	}
	if (env->j && env->str[env->i][env->j] == LABEL_CHAR)
	{
		arg = arg_create();
		arg->name = ft_strnew(env->j);
		arg->special |= T_LAB;
		arg->line = env->i;
		ft_strncpy(arg->name, &env->str[env->i][0], env->j);
		arg_add(&env->args, arg);
		env->j++;
		jump_space(env);
	}
	else
		env->j = 0;
}

static t_arg	*fill_arg(t_arg *arg, t_asm *env, int i, int len)
{
	arg = arg_create();
	arg->op_code = g_op_tab[i].op_code;
	arg->special |= T_INSTRU;
	arg->line = env->i;
	arg_add(&env->args, arg);
	env->j += len;
	env->oct_line = g_op_tab[i].op_code;
	return (arg);
}

int				find_ins(t_asm *env, t_arg **ref_inst)
{
	int		i;
	size_t	len;
	t_arg	*arg;

	i = 16;
	arg = NULL;
	if (env->str[env->i][env->j] == '\0')
		return (0);
	while (--i >= 0)
	{
		len = ft_strlen((const char*)g_op_tab[i].name);
		if (!ft_strncmp((const char*)g_op_tab[i].name,
			&env->str[env->i][env->j], len)
			&& ft_is_space(env->str[env->i][env->j + len]))
		{
			arg = fill_arg(arg, env, i, len);
			*ref_inst = arg;
			(*ref_inst)->tot_octets = 1;
			if (g_op_tab[i].has_ocp == 1)
				(*ref_inst)->tot_octets += 1;
			return (g_op_tab[i].n_args);
		}
	}
	show_err(5, env->i);
	return (0);
}

void			find_par(t_asm *env, unsigned char n_args, t_arg *ref_inst)
{
	char	**split;
	int		i;

	i = 0;
	jump_space(env);
	split = ft_strsplit(&env->str[env->i][env->j], ',');
	if (ft_strsplit_len(split) != n_args || split == NULL)
		show_err(8, env->i);
	while (split[i])
	{
		type_par(split[i], env, ref_inst);
		i++;
	}
	ft_strsplit_free(split);
	split = NULL;
}
