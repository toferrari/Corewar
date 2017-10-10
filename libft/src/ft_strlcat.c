/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:22:46 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/07 09:26:48 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	j = 0;
	while (src[j] != '\0' && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (i + j + 1 == size)
	{
		while (src[j] != '\0')
			j++;
	}
	return (i + j);
}
