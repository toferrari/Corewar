/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:53:22 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/11 12:08:29 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest_copy;
	unsigned char	*src_copy;

	dest_copy = (unsigned char*)dest;
	src_copy = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest_copy[i] = src_copy[i];
		if (dest_copy[i] == (unsigned char)c)
			return ((void*)&dest_copy[i + 1]);
		i++;
	}
	return (NULL);
}
