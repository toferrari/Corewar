/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:31:34 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 11:31:37 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strsplit_free(char **split)
{
	int		i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}
