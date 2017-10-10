/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:37:47 by tferrari          #+#    #+#             */
/*   Updated: 2017/07/26 15:54:32 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	aff(t_battle *battle, t_command *c)
{
	if (!ISREG(c->params[0]))
		return ;
	else
		ft_printf("%c", GETREGISTRE(c->params[0]) % 256);
}
