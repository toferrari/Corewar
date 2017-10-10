/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:04:13 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/10 11:35:33 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	copy;
	char	*finded;

	i = 0;
	finded = 0;
	copy = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == copy)
			finded = (char *)&s[i];
		i++;
	}
	if (finded)
		return (finded);
	if (copy == '\0')
		return ((char*)&s[i]);
	return (NULL);
}
