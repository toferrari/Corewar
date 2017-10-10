/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:17:38 by dbischof          #+#    #+#             */
/*   Updated: 2017/07/26 18:02:27 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*inttochar(int *i)
{
	int j;
	int tmp;

	j = -1;
	tmp = 0;
	while (++j < 4)
	{
		tmp = tmp << 8;
		tmp |= (0xff & *i);
		*i = *i >> 8;
	}
	*i = tmp;
	return ((char*)i);
}

int		chartoint(unsigned char *t, int len)
{
	int i;
	int tmp;

	i = -1;
	tmp = 0;
	while (++i < len && i < 4)
		tmp |= t[i] << (((len - 1) * 8) - (i * 8));
	return (tmp);
}
