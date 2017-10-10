/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fgets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeglain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:51:23 by mdeglain          #+#    #+#             */
/*   Updated: 2017/04/05 10:36:39 by mdeglain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_fgets(char *str, int max, t_file *file)
{
	int		c;
	char	*ptr;

	ptr = str;
	max--;
	while (max > 0)
	{
		if ((c = my_fgetc(file)) == EOF)
			break ;
		if (c == '\n')
			break ;
		*ptr++ = c;
		max--;
	}
	*ptr = '\0';
	if (c == EOF && !str[0])
		return (NULL);
	return (ptr);
}
