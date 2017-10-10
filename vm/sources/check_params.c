/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:27:25 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:27:30 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			check_params(t_battle *battle, int param, int size)
{
	if (size == 1 && ISREG(param))
		return (GETREGISTRE(param));
	return (param);
}
