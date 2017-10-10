/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:09:14 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:27:56 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*get_sign(t_data *data, long long nb)
{
	if (nb >= 0)
		return ("+");
	else
		return ("-");
}

static long long	di_type(t_data *data, va_list args)
{
	long long	nb;

	if (data->mod == l)
		nb = va_arg(args, long);
	else if (data->mod == ll)
		nb = va_arg(args, long long);
	else if (data->mod == h)
		nb = (short)va_arg(args, int);
	else if (data->mod == hh)
		nb = (signed char)va_arg(args, int);
	else if (data->mod == z)
		nb = va_arg(args, long long);
	else if (data->mod == j)
		nb = va_arg(args, intmax_t);
	else
		nb = va_arg(args, int);
	return (nb);
}

static void			di_process2(t_data *data, int len, long long nb)
{
	int			a;

	a = 0;
	if (((data->flags & FLAG_PLUS) || nb < 0) && (data->flags & FLAG_ZERO) &&
		data->min_w > len)
	{
		a = 1;
		write(1, get_sign(data, nb), 1);
	}
	min_width(data, len, 1);
	if (((data->flags & FLAG_PLUS) || nb < 0) && a == 0)
		write(1, get_sign(data, nb), 1);
	accu(data, len, nb);
	ft_putllnbr(nb);
}

static void			di_process(t_data *data, long long nb)
{
	int			len;

	len = ft_nblen(nb);
	if (!(check_null_number(data, nb)))
		return ;
	if ((data->flags & FLAG_PLUS) || nb < 0)
	{
		data->sign = 1;
	}
	if ((data->flags & FLAG_PLUS) && nb >= 0)
		len++;
	data->n += len;
	if (data->flags & FLAG_MINUS)
	{
		if ((data->flags & FLAG_PLUS) || nb < 0)
			write(1, get_sign(data, nb), 1);
		accu(data, len, nb);
		ft_putllnbr(nb);
		min_width(data, len, 1);
	}
	else
		di_process2(data, len, nb);
}

void				di_conv(t_data *data, va_list arg)
{
	long long	nb;

	nb = di_type(data, arg);
	if ((data->flags & FLAG_SPACE) && nb >= 0)
	{
		write(1, " ", 1);
		data->n++;
	}
	di_process(data, nb);
}
