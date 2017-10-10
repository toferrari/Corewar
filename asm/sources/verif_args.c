/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:15 by mdeglain          #+#    #+#             */
/*   Updated: 2017/05/29 10:39:13 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	verif_reg(t_asm *env, char *str)
{
	int	nb_digit;

	nb_digit = 0;
	str++;
	while (ft_isdigit(*str))
	{
		nb_digit++;
		str++;
	}
	while (*str)
	{
		if (!ft_is_space(*str))
			show_err(3, env->i);
		str++;
	}
	if (nb_digit < 1 && nb_digit > 2)
		show_err(3, env->i);
}

static void	verif_dir(t_asm *env, char *str)
{
	if (*str == ':')
	{
		while (*(++str) && !ft_is_space(*str))
			if (!is_in(LABEL_CHARS, *str))
				show_err(3, env->i);
	}
	else
	{
		if (*str != '-' && !ft_isdigit(*str))
			show_err(3, env->i);
		while (*(++str) && !ft_is_space(*str))
			if (!ft_isdigit(*str))
				show_err(3, env->i);
	}
	while (*str && *(++str))
		if (!ft_is_space(*str))
			show_err(3, env->i);
}

static void	verif_ind(t_asm *env, char *str)
{
	if (*str == ':')
	{
		while (*(++str) && !ft_is_space(*str))
			if (!is_in(LABEL_CHARS, *str))
				show_err(3, env->i);
	}
	else
	{
		if (*str != '-' && !ft_isdigit(*str))
			show_err(3, env->i);
		while (*(++str) && !ft_is_space(*str))
			if (!ft_isdigit(*str))
				show_err(3, env->i);
	}
	while (*str && *(++str))
		if (!ft_is_space(*str))
			show_err(3, env->i);
}

void		verif_name(t_asm *env, t_arg *arg)
{
	if (arg->special & T_REG)
	{
		verif_reg(env, arg->name);
		reg(env, ft_atoi(arg->name + 1));
	}
	else if (arg->special & T_DIR)
		verif_dir(env, arg->name);
	else if (arg->special & T_IND)
		verif_ind(env, arg->name);
	else
		show_err(3, env->i);
}
