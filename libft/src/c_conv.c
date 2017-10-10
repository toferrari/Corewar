/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 10:25:49 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:27:35 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	min_c_width(t_data *data, int len)
{
	int		tmp;

	tmp = 0;
	if (data->min_w > len)
		tmp = data->min_w - len;
	while (tmp > 0)
	{
		ft_putchar(' ');
		tmp--;
		data->n++;
	}
}

static void	c_conv2(t_data *data, va_list arg)
{
	int		len;
	wint_t	wc;

	if (data->mod == l)
	{
		wc = va_arg(arg, wint_t);
		if (0xd800 <= wc && wc <= 0xdfff)
			return ;
		min_c_width(data, ft_wcharlen(wc));
		len = ft_putwchar_fd(wc, 1);
	}
	else
	{
		(void)wc;
		min_c_width(data, 1);
		ft_putchar((char)va_arg(arg, int));
		len = 1;
	}
	data->n += len;
}

void		c_conv(t_data *data, va_list arg)
{
	int		len;
	wint_t	wc;

	if (data->flags & FLAG_MINUS)
	{
		if (data->mod == l)
		{
			wc = va_arg(arg, wint_t);
			if (0xD800 <= wc && wc <= 0xDFFF)
				return ;
			len = ft_putwchar_fd(va_arg(arg, wint_t), 1);
		}
		else
		{
			ft_putchar((char)va_arg(arg, int));
			len = 1;
			(void)wc;
		}
		min_c_width(data, len);
		data->n += len;
	}
	else
		c_conv2(data, arg);
}
