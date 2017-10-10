/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:55:40 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/10 18:19:35 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int	i;
	int result;

	i = 1;
	result = nb;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
