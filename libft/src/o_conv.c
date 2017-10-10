/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:10:48 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:28:24 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			o_process2(t_data *data, char *str, ULL nb, int len)
{
	int					a;

	a = 0;
	if ((data->flags & FLAG_SHARP) && nb != 0)
		len++;
	if ((data->flags & FLAG_SHARP) && data->min_w < len && nb != 0)
	{
		a = 1;
		write(1, "0", 1);
	}
	min_width(data, len, 1);
	if ((data->flags & FLAG_SHARP) && a == 0 && nb != 0)
		write(1, "0", 1);
	accu(data, len, nb);
	ft_putstr(str);
}

static void			o_mprocess(t_data *data, char *str, ULL nb, int len)
{
	if ((data->flags & FLAG_SHARP) && data->accu < len && nb != 0)
	{
		write(1, "0", 1);
		len++;
	}
	accu(data, len, nb);
	ft_putstr(str);
	min_width(data, len, 1);
}

void				o_process(t_data *data, va_list arg)
{
	unsigned long long	nb;
	char				*str;
	int					len;

	nb = oux_type(data, arg);
	str = ft_base(nb, 8, "01234567");
	len = ft_strlen(str);
	if (!(check_null_number(data, nb)) && !(data->flags & FLAG_SHARP))
		return ;
	data->n += len;
	if ((data->flags & FLAG_SHARP) && nb != 0)
		data->n++;
	if (data->flags & FLAG_MINUS)
		o_mprocess(data, str, nb, len);
	else
		o_process2(data, str, nb, len);
	free(str);
}

unsigned long long	oux_type(t_data *data, va_list arg)
{
	unsigned long long nb;

	if (data->mod == l)
		nb = va_arg(arg, unsigned long);
	else if (data->mod == ll)
		nb = va_arg(arg, unsigned long long);
	else if (data->mod == h)
		nb = (unsigned short)va_arg(arg, unsigned int);
	else if (data->mod == hh)
		nb = (unsigned char)va_arg(arg, unsigned int);
	else if (data->mod == z)
		nb = va_arg(arg, size_t);
	else if (data->mod == j)
		nb = va_arg(arg, uintmax_t);
	else
		nb = va_arg(arg, unsigned int);
	return (nb);
}
