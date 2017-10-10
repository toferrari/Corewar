/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:00:23 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:27:46 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conversion(t_data *data, va_list arg)
{
	if (ft_strchr("pdDioOcCxXuUsS%bB", *(data->fmt)))
	{
		(((t_conv*)(data->tab))[*(data->fmt)])(data, arg);
		data->fmt++;
	}
	else if ((*data->fmt) != '\0')
	{
		ft_putchar(*(data->fmt));
		data->n++;
		data->fmt++;
	}
}
