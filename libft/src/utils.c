/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 09:58:21 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:29:41 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_null(t_data *data)
{
	ft_putstr("(null)");
	data->n += 6;
}

int		check_null_number(t_data *data, ULL nb)
{
	if (data->accu == 0 && nb == 0)
	{
		min_width(data, 0, 1);
		return (0);
	}
	return (1);
}
