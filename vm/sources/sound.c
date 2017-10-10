/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:32:43 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:32:45 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sound(t_battle *battle)
{
	pid_t		id;
	static char	*tab[] = {
						"/usr/bin/afplay",
						"sound/0437.mp3",
						NULL
	};

	id = fork();
	if (id <= 0)
		execve(tab[0], tab, battle->env);
}
