/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:02:13 by tferrari          #+#    #+#             */
/*   Updated: 2017/09/19 15:54:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		help(void)
{
	ft_printf("Usage: ./corewar [-dump -c -v -n] <champion1.cor>\n");
	ft_printf("#### TEXT OUTPUT MODE ######################################\n");
	ft_printf("	-dump N		: Dumps memory after N cycles then exits\n");
	ft_printf("	-n N		: Give ID to champ\n");
	ft_printf("	-v N		: Verbosity levels, can be added together");
	ft_printf(" to enable several\n");
	ft_printf("			- 4 : Show operations\n");
	ft_printf("#### NCURSES MODE ##########################################\n");
	ft_printf("	-c		: launch ncurses\n");
	ft_printf("############################################################\n");
	return (0);
}
