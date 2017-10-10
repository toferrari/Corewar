/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:57:57 by mdeglain          #+#    #+#             */
/*   Updated: 2016/11/11 12:44:12 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (s == NULL)
		return (0);
	start = 0;
	while (s[start] != '\0' && (s[start] == ' ' || s[start] == '\t'
				|| s[start] == '\n'))
		start++;
	end = ft_strlen(s);
	while (start < end && (s[end - 1] == ' ' || s[end - 1] == '\n'
				|| s[end - 1] == '\t'))
		end--;
	if (end == start)
		return (ft_strdup(""));
	len = end - start;
	return (ft_strsub(s, start, len));
}
