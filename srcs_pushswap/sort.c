/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/30 20:34:04 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

void	sort(t_list **lst_a, t_list **lst_b)
{
	int		max;

	split1(lst_a, lst_b, 0);
	sort1(lst_a, lst_b, 0);
	max = split2(lst_a, lst_b);
	max = split2bis(lst_a, lst_b, max);
	while (max)
	{
		pb(*lst_a, *lst_b);
		ft_printf("pb\n");
		if (lastval(*lst_b) < blastval(*lst_b))
		{
			sb(lst_b);
			ft_printf("sb\n");
		}
		max--;
	}
	merge2(lst_a, lst_b, 0);
}
