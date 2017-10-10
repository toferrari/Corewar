/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:56:28 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/11 12:39:58 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	s_len;
	char	*res;

	if (s == NULL || f == NULL)
		return (0);
	s_len = ft_strlen(s);
	res = (char *)malloc((s_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
