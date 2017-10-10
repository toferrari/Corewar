/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:25:57 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:29:09 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sml_case(t_data *data, va_list arg)
{
	wchar_t	*str;
	int		len;
	int		strlen;

	if ((str = va_arg(arg, wchar_t*)) == NULL)
	{
		write_null(data);
		return ;
	}
	strlen = ft_wstrlen(str);
	if (data->accu != -1 && data->accu < strlen)
		strlen = data->accu;
	strlen = ft_wnstrlen(str, strlen);
	len = data->min_w - strlen;
	if (data->min_w)
	{
		if (data->min_w < strlen)
			len = 0;
		data->n += strlen;
	}
	else
		data->n += strlen;
	ft_putnwstr(str, data->accu);
	min_width(data, len, 0);
}

static void	sl_case(t_data *data, va_list arg)
{
	wchar_t	*str;
	int		len;
	int		strlen;

	if ((str = va_arg(arg, wchar_t*)) == NULL)
	{
		write_null(data);
		return ;
	}
	strlen = ft_wstrlen(str);
	if (data->accu != -1 && data->accu < strlen)
		strlen = data->accu;
	strlen = ft_wnstrlen(str, strlen);
	len = data->min_w - strlen;
	if (data->min_w)
	{
		if (data->min_w < strlen)
			len = 0;
		data->n += strlen;
	}
	else
		data->n += strlen;
	min_width(data, len, 0);
	ft_putnwstr(str, data->accu);
}

static void	sm_case(t_data *data, va_list arg)
{
	char	*str;
	int		len;
	int		strlen;

	if ((str = va_arg(arg, char*)) == NULL)
	{
		write_null(data);
		return ;
	}
	strlen = ft_strlen(str);
	if (data->accu != -1 && data->accu < (int)ft_strlen(str))
		strlen = data->accu;
	len = data->min_w - strlen;
	if (data->min_w)
	{
		if (data->min_w < strlen)
			len = 0;
		data->n += strlen;
	}
	else
		data->n += strlen;
	ft_putnstr(str, data->accu);
	min_width(data, len, 0);
}

static void	s_case(t_data *data, va_list arg)
{
	char	*str;
	int		len;
	int		strlen;

	if ((str = va_arg(arg, char*)) == NULL)
	{
		write_null(data);
		return ;
	}
	strlen = ft_strlen(str);
	if (data->accu != -1 && data->accu < (int)ft_strlen(str))
		strlen = data->accu;
	len = data->min_w - strlen;
	if (data->min_w)
	{
		if (data->min_w < strlen)
			len = 0;
		data->n += strlen;
	}
	else
		data->n += strlen;
	min_width(data, len, 0);
	ft_putnstr(str, data->accu);
}

void		s_conv(t_data *data, va_list arg)
{
	if (data->flags & FLAG_MINUS)
	{
		if (data->mod == l)
			sml_case(data, arg);
		else
			sm_case(data, arg);
	}
	else
	{
		if (data->mod == l)
			sl_case(data, arg);
		else
			s_case(data, arg);
	}
}
