/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:11:42 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/12 09:17:47 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	reg_add(t_asm *env, int reg)
{
	int	i;

	i = -1;
	while (++i < REG_NUMBER)
	{
		if (env->reg[i] == -1)
		{
			env->reg[i] = reg;
			return (1);
		}
	}
	ft_putstr_fd("Too much registre used. Only ", 2);
	ft_putnbr_fd(REG_NUMBER, 2);
	ft_putendl_fd(" are allowed.", 2);
	exit(EXIT_FAILURE);
	return (0);
}

int			reg(t_asm *env, int reg)
{
	int	i;

	i = -1;
	while (++i < REG_NUMBER)
		if (env->reg[i] == reg)
			return (1);
	reg_add(env, reg);
	return (1);
}
