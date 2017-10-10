/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:57:12 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/24 13:21:45 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	mem = (char *)malloc((size + 1) * sizeof(char));
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
