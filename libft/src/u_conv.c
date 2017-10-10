/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:09:01 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:29:19 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	u_process2(t_data *data, char *str, ULL nb, int len)
{
	min_width(data, len, 1);
	accu(data, len, nb);
	ft_putstr(str);
}

void		u_process(t_data *data, va_list arg)
{
	unsigned long long	nb;
	int					len;
	char				*str;

	nb = oux_type(data, arg);
	str = ft_base(nb, 10, "0123456789");
	len = ft_strlen(str);
	if (!(check_null_number(data, nb)))
		return ;
	data->n += len;
	if (data->flags & FLAG_MINUS)
	{
		accu(data, len, nb);
		ft_putstr(str);
		min_width(data, len, 1);
	}
	else
		u_process2(data, str, nb, len);
	free(str);
}
