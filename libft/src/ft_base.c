/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:15:40 by mdeglain          #+#    #+#             */
/*   Updated: 2017/01/27 16:05:24 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base(unsigned long long nb, int base, char *mbr)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * 100);
	if (nb == 0)
		str[i++] = '0';
	while (nb != 0)
	{
		str[i] = mbr[nb % base];
		nb = nb / base;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
