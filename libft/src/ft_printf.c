/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:30:44 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:30:18 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		conv_init(t_data *data)
{
	t_conv	*tab;

	tab = (t_conv*)malloc(sizeof(t_conv) * 127);
	data->tab = tab;
	tab['s'] = s_conv;
	tab['S'] = upper_s_conv;
	tab['p'] = p_conv;
	tab['d'] = di_conv;
	tab['D'] = upper_d_conv;
	tab['i'] = di_conv;
	tab['o'] = o_process;
	tab['O'] = upper_o_conv;
	tab['u'] = u_process;
	tab['U'] = upper_u_conv;
	tab['x'] = x_process;
	tab['X'] = x_process;
	tab['c'] = c_conv;
	tab['C'] = upper_c_conv;
	tab['%'] = pct_conv;
	tab['b'] = b_process;
	tab['B'] = b_process;
}

static void	init(char *format, t_data *data, va_list arg)
{
	conv_init(data);
	data->fmt = format;
	launch(data, arg);
}

static void	data_free(t_data *data)
{
	free(data->tab);
	free(data);
}

void		launch(t_data *data, va_list arg)
{
	data->n = 0;
	while (*(data->fmt))
	{
		if (*(data->fmt) == '%')
		{
			data->fmt++;
			parsing(data, arg);
		}
		else
		{
			ft_putchar(*(data->fmt));
			data->n++;
			data->fmt++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	t_data	*data;
	int		len;
	va_list	arg;

	va_start(arg, format);
	data = (t_data*)malloc(sizeof(t_data));
	init((char*)format, data, arg);
	len = data->n;
	data_free(data);
	va_end(arg);
	return (len);
}
