/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:08:34 by mdeglain          #+#    #+#             */
/*   Updated: 2017/01/30 14:54:48 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, int nb)
{
	int	i;

	i = 0;
	if (nb == -1)
	{
		ft_putstr(str);
		return ;
	}
	while (i != nb && str[i])
		ft_putchar(str[i++]);
}
