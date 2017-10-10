/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:43:35 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/10 11:23:14 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if ((s1[i] == '\0' && s2[i] == '\0') || len == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < len - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
