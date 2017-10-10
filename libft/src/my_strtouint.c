/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtouint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:00:06 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 16:02:38 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	str_to_uint(char *s)
{
	unsigned int n;

	n = 0;
	while (*s && ft_isdigit(*s))
	{
		if ((n & (~0ull << 60)) && n > (UINT_MAX - (*s - '0')) / 10)
		{
			ft_printf("Error overflow\n");
			exit(EXIT_FAILURE);
		}
		n = (n * 10) + (*s - '0');
		s++;
	}
	return (n);
}
