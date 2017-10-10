/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:12:38 by mdeglain          #+#    #+#             */
/*   Updated: 2017/01/30 10:26:14 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(wint_t *str, int nb)
{
	int	i;

	i = 0;
	if (nb == -1)
	{
		ft_putwstr(str);
		return ;
	}
	while (i < nb && ft_wcharlen(*str) + i <= nb)
	{
		i += ft_putwchar_fd(*str, 1);
		str++;
	}
}
