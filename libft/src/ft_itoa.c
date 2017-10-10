/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:52:48 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/10 14:03:11 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lennbr(int nb)
{
	size_t		len;

	if (0 == nb)
		return (1);
	len = 0;
	if (0 > nb)
		len++;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*res;

	len = ft_lennbr(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len] = 0;
	if ((-2147483647 - 1) == n)
		return (ft_strcpy(res, "-2147483648"));
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		len--;
		res[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
