/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:26:44 by mdeglain          #+#    #+#             */
/*   Updated: 2017/02/03 11:48:31 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	mem;
	int	is_neg;

	i = 0;
	is_neg = 1;
	while (str[i] == '\r' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	mem = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		mem = (mem * 10) + str[i] - '0';
		i++;
	}
	return (is_neg * mem);
}
