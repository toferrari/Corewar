/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_w.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:49:51 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/30 10:28:14 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	blank_char(t_data *data, char c, int nb_c)
{
	int		i;

	i = 0;
	while (i < nb_c)
	{
		write(1, &c, 1);
		data->n++;
		i++;
	}
}

static void	min_w_s(t_data *data, int len)
{
	blank_char(data, ' ', len);
}

static void	min_w_n(t_data *data, int len)
{
	int		tmp;

	tmp = data->min_w - len;
	if (data->accu > data->min_w)
		tmp = 0;
	else if (data->accu >= len && data->min_w > data->accu)
		tmp = data->min_w - data->accu - data->sign;
	if (data->flags & FLAG_SPACE)
		tmp--;
	if ((data->flags & FLAG_ZERO) && data->accu < 0)
		blank_char(data, '0', tmp);
	else
		blank_char(data, ' ', tmp);
}

void		accu(t_data *data, int len, long long nb)
{
	int		tmp;

	tmp = 0;
	if ((data->flags & FLAG_PLUS) || nb < 0)
		len--;
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

void		min_width(t_data *data, int len, int id)
{
	if (id == 0)
		min_w_s(data, len);
	else
		min_w_n(data, len);
}
