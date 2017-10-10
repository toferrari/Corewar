/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baselen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:02:42 by mdeglain          #+#    #+#             */
/*   Updated: 2017/01/05 11:16:27 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_baselen(int nb, int base, char *mbr)
{
	char	*str;
	int		i;
	int		ret;

	i = 0;
	str = (char*)malloc(sizeof(char) * 100);
	while (1)
	{
		if (nb < base)
		{
			str[i] = mbr[nb];
			break ;
			ft_putstr("test");
		}
		str[i] = mbr[nb % base];
		nb = nb / base;
		i++;
	}
	ret = ft_strlen(str);
	free(str);
	return (ret);
}
