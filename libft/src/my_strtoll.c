/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:57:03 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 15:57:29 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	str_to_ll(char *s)
{
	unsigned long long n;

	if (*s == '-')
	{
		n = str_to_ull(s + 1);
		if ((long long)(-n) >= 0)
		{
			ft_printf("Error overflow\n");
			exit(EXIT_FAILURE);
		}
		n *= -1;
	}
	else
	{
		if (*s == '+')
			s++;
		n = str_to_ull(s);
		if ((long long)n < 0)
		{
			ft_printf("Error overflow\n");
			exit(EXIT_FAILURE);
		}
	}
	return (n);
}
