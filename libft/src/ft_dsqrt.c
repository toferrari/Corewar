/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dsqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:29:31 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/11 11:54:49 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_dsqrt(double nb)
{
	int		prev;
	int		k;
	int		kmax;
	double	s;

	s = 1;
	k = 0;
	kmax = 100;
	while (k < kmax)
	{
		prev = s;
		s = (s + nb / s) / 2;
		if (prev == s)
			break ;
		k++;
	}
	return (s);
}
