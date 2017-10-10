/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:59:15 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 15:59:56 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	str_to_l(char *s)
{
	unsigned long n;

	if (*s == '-')
	{
		n = str_to_ul(s + 1);
		if ((long)(-n) >= 0)
		{
			ft_printf("Error overflow\n");
			abort();
		}
		n *= -1;
	}
	else
	{
		if (*s == '+')
			s++;
		n = str_to_ul(s);
		if ((long)n < 0)
		{
			ft_printf("Error overflow\n");
			abort();
		}
	}
	return (n);
}
