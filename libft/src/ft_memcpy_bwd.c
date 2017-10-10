/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:23:04 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/11 13:32:13 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_bwd(void *dst, const void *src, size_t n)
{
	char	*copy_dst;
	char	*copy_src;

	if (n == 0 || dst == src)
		return (dst);
	copy_dst = (char*)dst;
	copy_src = (char*)src;
	while (n--)
		copy_dst[n] = copy_src[n];
	return (dst);
}
