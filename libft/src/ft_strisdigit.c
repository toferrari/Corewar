/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:55:01 by mdeglain          #+#    #+#             */
/*   Updated: 2017/03/23 11:55:02 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisdigit(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
