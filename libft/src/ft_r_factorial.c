/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_factorial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:00:44 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/11 10:50:19 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_r_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb > 1)
		return (result * ft_r_factorial(nb - 1));
	else
		return (1);
}
