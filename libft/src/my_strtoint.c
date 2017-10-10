/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:01:00 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 16:02:27 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_to_int(char *s)
{
	unsigned int n;

	if (*s == '-')
	{
		n = str_to_uint(s + 1);
		if ((int)(-n) >= 0)
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
		n = str_to_uint(s);
		if ((int)n < 0)
		{
			ft_printf("Error overflow\n");
			exit(EXIT_FAILURE);
		}
	}
	return (n);
}
