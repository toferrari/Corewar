/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:26:32 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:28:58 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pct_conv(t_data *data, va_list arg)
{
	if (data->flags & FLAG_MINUS)
	{
		ft_putchar('%');
		min_width(data, 1, 1);
	}
	else
	{
		min_width(data, 1, 1);
		ft_putchar('%');
	}
	data->n++;
}
