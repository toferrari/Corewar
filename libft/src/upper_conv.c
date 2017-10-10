/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:53:28 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:29:28 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	upper_s_conv(t_data *data, va_list arg)
{
	data->mod = l;
	s_conv(data, arg);
}

void	upper_d_conv(t_data *data, va_list arg)
{
	data->mod = l;
	di_conv(data, arg);
}

void	upper_u_conv(t_data *data, va_list arg)
{
	data->mod = l;
	u_process(data, arg);
}

void	upper_o_conv(t_data *data, va_list arg)
{
	data->mod = l;
	o_process(data, arg);
}

void	upper_c_conv(t_data *data, va_list arg)
{
	data->mod = l;
	c_conv(data, arg);
}
