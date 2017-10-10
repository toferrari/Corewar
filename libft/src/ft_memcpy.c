/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:53:43 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/24 13:20:12 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_copy;
	char		*src_copy;

	dst_copy = (char*)dst;
	src_copy = (char*)src;
	while (n > 0)
	{
		*dst_copy++ = *src_copy++;
		n--;
	}
	return (dst);
}
