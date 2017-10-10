/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:19:28 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:28:34 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_conv(t_data *data, va_list arg)
{
	char		*str;
	long long	nb;
	int			len;

	nb = (long long)va_arg(arg, void*);
	len = -2;
	str = ft_base(nb, 16, "0123456789abcdef");
	data->n += ft_strlen(str) + 2;
	if (data->min_w && data->min_w > ft_strlen(str) + 2)
		len = data->min_w - ft_strlen(str) - 2;
	if (data->flags & FLAG_MINUS)
	{
		write(1, "0x", 2);
		ft_putstr(str);
		min_width(data, len, 0);
	}
	else
	{
		min_width(data, len, 0);
		write(1, "0x", 2);
		ft_putstr(str);
	}
	free(str);
}
