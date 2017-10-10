/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:53:29 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 10:37:11 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(char *s, char c, size_t n)
{
	char	*s_copy;
	char	c_copy;

	s_copy = s;
	c_copy = c;
	while (n--)
	{
		if (*s_copy == c_copy)
			return ((void*)s_copy);
		if (n)
			s_copy++;
	}
	return (NULL);
}
