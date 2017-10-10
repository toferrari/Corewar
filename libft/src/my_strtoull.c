/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtoull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:53:14 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 16:02:53 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	str_to_ull(char *s)
{
	unsigned long long n;

	n = 0;
	while (*s && ft_isdigit(*s))
	{
		if ((n & (~0ull << 60)) && n > (ULLONG_MAX - (*s - '0')) / 10)
		{
			ft_printf("Error overflow\n");
			exit(EXIT_FAILURE);
		}
		n = (n * 10) + (*s - '0');
		s++;
	}
	return (n);
}
