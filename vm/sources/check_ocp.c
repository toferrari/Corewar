/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:27:20 by tferrari          #+#    #+#             */
/*   Updated: 2017/08/01 15:27:21 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define C(a, b, c)	(a << 6 | b << 4 | c << 2)
#define RRR		C(R, R, R)
#define RIR		C(R, I, R)
#define RDR		C(R, D, R)
#define DRR		C(D, R, R)
#define DIR		C(D, I, R)
#define DDR		C(D, D, R)
#define IRR		C(I, R, R)
#define IIR		C(I, I, R)
#define IDR		C(I, D, R)
#define IRZ		C(I, R, Z)

int			check_ocp(char inst, char ocp)
{
	const char	tab[16][10] = {
				{0},
				{C(D, R, Z), IRZ, 0},
				{C(R, I, Z), C(R, R, Z), 0},
				{RRR, 0},
				{RRR, 0},
				{RRR, RIR, RDR, DRR, DIR, DDR, IRR, IIR, IDR, 0},
				{RRR, RIR, RDR, DRR, DIR, DDR, IRR, IIR, IDR, 0},
				{RRR, RIR, RDR, DRR, DIR, DDR, IRR, IIR, IDR, 0},
				{0},
				{RDR, RRR, DDR, DRR, IDR, IRR, 0},
				{C(R, R, D), RRR, C(R, D, D), RDR, C(R, I, D), RIR, 0},
				{0},
				{C(D, R, Z), IRZ, 0},
				{RDR, RRR, DIR, DRR, IDR, IRR, 0},
				{0},
				{0},
	};

	return (!!ft_strchr(tab[(int)inst - 1], ocp));
}
