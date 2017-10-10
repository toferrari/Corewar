/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:57:32 by mdeglain          #+#    #+#             */
/*   Updated: 2017/02/21 14:57:21 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countstr(char *str, char c)
{
	size_t		in_str;
	size_t		nb_str;
	size_t		i;

	i = 0;
	in_str = 0;
	nb_str = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			in_str = 0;
		else if (str[i] != c && in_str == 0)
		{
			in_str = 1;
			nb_str++;
		}
		i++;
	}
	return (nb_str);
}

static char		*ft_nextstr(char **str, char c)
{
	size_t		len;
	char		*result;
	char		*end;

	if (**str == c)
		(*str)++;
	if (**str == c)
		return (NULL);
	while (ft_is_space(**str))
		(*str)++;
	end = ft_strchr(*str, c);
	if (end == NULL)
		len = ft_strlen(*str);
	else
		len = end - *str;
	result = ft_strsub(*str, 0, len);
	*str = *str + len;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		nb_str;
	size_t		i;
	char		**result;
	char		*new;

	if (s == NULL)
		return (0);
	new = (char*)s;
	nb_str = ft_countstr(new, c);
	result = (char**)malloc((nb_str + 1) * sizeof(char*));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < nb_str)
	{
		result[i] = ft_nextstr(&new, c);
		i++;
	}
	result[i] = 0;
	return (result);
}
