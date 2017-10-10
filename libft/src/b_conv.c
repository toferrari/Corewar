/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:52:34 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:27:04 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	b_prefix(t_data *data, unsigned long long nb)
{
	if (nb == 0)
		return ;
	if (*data->fmt == 'B')
		write(1, "0B", 2);
	else
		write(1, "0b", 2);
	data->n += 2;
}

static void	b_process2(t_data *data, char *str, ULL nb, int len)
{
	int					a;

	a = 0;
	if (data->min_w < len && (data->flags & FLAG_SHARP) && data->accu < len)
	{
		a = 1;
		b_prefix(data, nb);
	}
	if (a == 0 && (data->flags & FLAG_SHARP) && (data->flags & FLAG_ZERO))
	{
		b_prefix(data, nb);
		a = 1;
	}
	min_width(data, len, 1);
	if (data->flags & FLAG_SHARP && a == 0)
	{
		b_prefix(data, nb);
	}
	accu_oux(data, len);
	ft_putstr(str);
}

void		b_process(t_data *data, va_list arg)
{
	unsigned long long	nb;
	int					len;
	char				*str;

	nb = oux_type(data, arg);
	str = ft_base(nb, 2, "01");
	len = ft_strlen(str);
	if (!(check_null_number(data, nb)))
		return ;
	data->n += len;
	if ((data->flags & FLAG_SHARP) && nb != 0)
		len += 2;
	if (data->flags & FLAG_MINUS)
	{
		if (data->flags & FLAG_SHARP)
			b_prefix(data, nb);
		accu_oux(data, len);
		ft_putstr(str);
		min_width(data, len, 1);
	}
	else
		b_process2(data, str, nb, len);
	free(str);
}
