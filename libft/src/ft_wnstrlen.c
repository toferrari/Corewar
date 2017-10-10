/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wnstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:20:16 by mdeglain          #+#    #+#             */
/*   Updated: 2017/01/24 17:20:18 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wnstrlen(const wint_t *str, int nb)
{
	int	res;

	res = 0;
	while (*str && ft_wcharlen(*str) + res <= nb)
	{
		if (*str <= 0x7F)
			res += 1;
		else if (*str <= 0x7FF)
			res += 2;
		else if (*str <= 0xFFFF)
			res += 3;
		else if (*str <= 0x10FFFF)
			res += 4;
		str++;
	}
	return (res);
}
