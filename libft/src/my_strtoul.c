/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:58:04 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 16:03:13 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	str_to_ul(char *s)
{
	unsigned long n;

	n = 0;
	while (*s && ft_isdigit(*s))
	{
		if ((n & (~0ull << 60)) && n > (ULONG_MAX - (*s - '0')) / 10)
		{
			ft_printf("Error overflow\n");
			exit(EXIT_FAILURE);
		}
		n = (n * 10) + (*s - '0');
		s++;
	}
	return (n);
}
