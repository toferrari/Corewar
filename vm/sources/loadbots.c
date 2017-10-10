/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadbots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:30:57 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 17:15:15 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		getidparam(char **av, int i)
{
	int id;

	id = 0;
	if (i - 2 >= 0 && ft_strequ(av[i - 2], "-n"))
		id = ft_atoi(av[i - 1]);
	return (id);
}

int		checkid(t_bots *bots, int id)
{
	int i;

	i = -1;
	while (++i < bots->nb)
		if (bots->tab[i]->id == id)
			return (0);
	return (1);
}

void	getuniqid(t_bots *bots)
{
	static int	id = 0;
	int			i;

	i = -1;
	while (++i < bots->nb)
		if (!bots->tab[i]->id)
		{
			while (!checkid(bots, --id))
				;
			bots->tab[i]->id = id;
		}
}

int		checkids(t_bots *bots)
{
	int i;
	int j;

	i = -1;
	while (++i < bots->nb)
	{
		j = i;
		while (++j < bots->nb)
			if (bots->tab[i]->id == bots->tab[j]->id)
				return (0);
	}
	return (1);
}

t_bots	loadbots(int ac, char **av)
{
	int		i;
	t_bot	*tmp;
	t_bots	bots;

	i = 0;
	bots.nb = 0;
	while (++i < ac && bots.nb < MAX_PLAYERS)
	{
		if (av[i][0] != '-' && (tmp = creabot(av[i])))
		{
			bots.tab[bots.nb] = tmp;
			bots.tab[bots.nb]->id = getidparam(av, i);
			bots.tab[bots.nb]->rid = bots.nb;
			bots.nb++;
		}
	}
	getuniqid(&bots);
	if (!checkids(&bots))
	{
		ft_printf("error id\n");
		bots.nb = 0;
	}
	return (bots);
}
