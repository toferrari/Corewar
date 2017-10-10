/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:53:10 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/24 13:21:31 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	mem = (char *)malloc(size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
