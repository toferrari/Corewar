/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:30:59 by mdeglain          #+#    #+#             */
/*   Updated: 2017/01/24 10:47:55 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstrlen(const wint_t *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			nb += 1;
		else if (*str <= 0x7FF)
			nb += 2;
		else if (*str <= 0xFFFF)
			nb += 3;
		else if (*str <= 0x10FFFF)
			nb += 4;
		str++;
	}
	return (nb);
}
