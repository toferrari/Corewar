/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <mdeglain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 09:35:03 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/09 10:52:49 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		cor_strlen(char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(*str))
		str++;
	while (!ft_is_space(*str) && *str != LABEL_CHAR && *str)
	{
		i++;
		str++;
	}
	return (i);
}

int		cor_strchr(const char *s, int c)
{
	int		i;
	int		is_quote;

	i = 0;
	is_quote = 0;
	while (s[i])
	{
		if (s[i] == '"')
			is_quote = !is_quote;
		if (s[i] == c && !is_quote)
			return (i);
		i++;
	}
	return (-1);
}

int		is_in(const char *str, char letter)
{
	while (*str)
	{
		if (*str == letter)
			return (1);
		str++;
	}
	return (0);
}

void	jump_space(t_asm *env)
{
	while (ft_is_space(env->str[env->i][env->j]))
		env->j++;
}

int		new_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str && !(ft_is_space(*str)))
	{
		len++;
		str++;
	}
	return (len);
}
