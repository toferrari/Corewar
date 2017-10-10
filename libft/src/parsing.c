/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:58:27 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:28:45 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	modifier_parsing(t_data *data, va_list arg)
{
	if (*(data->fmt) == 'h' && *(data->fmt + 1) == 'h')
		data->mod = hh;
	else if (*(data->fmt) == 'h')
		data->mod = h;
	else if (*(data->fmt) == 'l' && *(data->fmt + 1) == 'l')
		data->mod = ll;
	else if (*(data->fmt) == 'l')
		data->mod = l;
	else if (*(data->fmt) == 'j')
		data->mod = j;
	else if (*(data->fmt) == 'z')
		data->mod = z;
	else
		data->mod = no_mod;
	if (data->mod == ll || data->mod == hh)
		data->fmt += 2;
	else if (data->mod != no_mod)
		data->fmt++;
}

static void	accuracy_parsing(t_data *data, va_list arg)
{
	int	accu;

	if (*(data->fmt) == '.')
	{
		data->accu = 0;
		data->fmt++;
		if (*(data->fmt) == '*')
		{
			accu = va_arg(arg, int);
			data->accu = accu;
			if (accu < 0)
				data->accu = -1;
			data->fmt++;
		}
		else
		{
			while (ft_isdigit(*(data->fmt)))
			{
				data->accu = data->accu * 10 + (*(data->fmt) - '0');
				data->fmt++;
			}
		}
	}
	modifier_parsing(data, arg);
}

static void	width_parsing(t_data *data, va_list arg)
{
	int	min_w;

	if (*(data->fmt) == '*')
	{
		min_w = va_arg(arg, int);
		data->min_w = min_w;
		if (min_w < 0)
		{
			data->flags |= FLAG_MINUS;
			data->min_w = ft_abs(min_w);
		}
		data->fmt++;
	}
	else
	{
		while (ft_isdigit(*(data->fmt)))
		{
			data->min_w = data->min_w * 10 + (*(data->fmt) - '0');
			data->fmt++;
		}
	}
	accuracy_parsing(data, arg);
}

static void	flag_parsing(t_data *data, va_list arg)
{
	data->flags = 0;
	while (*(data->fmt) && ft_strchr(" 0+-#", *(data->fmt)))
	{
		if (*(data->fmt) == ' ')
			data->flags |= FLAG_SPACE;
		else if (*(data->fmt) == '0')
			data->flags |= FLAG_ZERO;
		else if (*(data->fmt) == '+')
			data->flags |= FLAG_PLUS;
		else if (*(data->fmt) == '-')
			data->flags |= FLAG_MINUS;
		else
			data->flags |= FLAG_SHARP;
		data->fmt++;
	}
	if (data->flags & FLAG_ZERO && data->flags & FLAG_MINUS)
		data->flags -= FLAG_ZERO;
	if (data->flags & FLAG_PLUS && data->flags & FLAG_SPACE)
		data->flags -= FLAG_SPACE;
	width_parsing(data, arg);
}

void		parsing(t_data *data, va_list arg)
{
	data->flags = 0;
	data->min_w = 0;
	data->accu = -1;
	data->sign = 0;
	data->mod = no_mod;
	flag_parsing(data, arg);
	conversion(data, arg);
}
