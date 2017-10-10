/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:31:04 by lbrugero          #+#    #+#             */
/*   Updated: 2017/03/14 15:31:05 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsplit_len(char **split)
{
	int		size;

	size = 0;
	if (split == NULL)
		return (-1);
	while (split[size] != NULL)
		size++;
	return (size);
}
