/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:57:45 by mdeglain          #+#    #+#             */
/*   Updated: 2017/02/15 10:19:22 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (s == NULL)
		return (0);
	mem = (char*)malloc(sizeof(mem) * (len + 1));
	if (mem == NULL)
		return (NULL);
	mem[len] = '\0';
	return (ft_strncpy(mem, &s[start], len));
}
