/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:55:53 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:29:53 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prefix(t_data *data, unsigned long long nb)
{
	if (nb == 0)
		return ;
	if (*data->fmt == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	data->n += 2;
}

static char	*get_mbr(t_data *data)
{
	if (*data->fmt == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

static void	x_process2(t_data *data, char *str, ULL nb, int len)
{
	int					a;

	a = 0;
	if (data->min_w < len && (data->flags & FLAG_SHARP) && data->accu < len)
	{
		a = 1;
		prefix(data, nb);
	}
	if (a == 0 && (data->flags & FLAG_SHARP) && (data->flags & FLAG_ZERO))
	{
		prefix(data, nb);
		a = 1;
	}
	min_width(data, len, 1);
	if (data->flags & FLAG_SHARP && a == 0)
	{
		prefix(data, nb);
	}
	accu_oux(data, len);
	ft_putstr(str);
}

void		x_process(t_data *data, va_list arg)
{
	unsigned long long	nb;
	int					len;
	char				*mbr;
	char				*str;

	nb = oux_type(data, arg);
	mbr = get_mbr(data);
	str = ft_base(nb, 16, mbr);
	len = ft_strlen(str);
	if (!(check_null_number(data, nb)))
		return ;
	data->n += len;
	if ((data->flags & FLAG_SHARP) && nb != 0)
		len += 2;
	if (data->flags & FLAG_MINUS)
	{
		if (data->flags & FLAG_SHARP)
			prefix(data, nb);
		accu_oux(data, len);
		ft_putstr(str);
		min_width(data, len, 1);
	}
	else
		x_process2(data, str, nb, len);
	free(str);
}

void		accu_oux(t_data *data, int len)
{
	int					tmp;

	tmp = 0;
	if (data->flags & FLAG_SHARP)
		len -= 2;
	if (data->accu == -1)
		return ;
	if (data->accu > len)
		tmp = data->accu - len;
	while (tmp > 0)
	{
		ft_putchar('0');
		tmp--;
		data->n++;
	}
}
