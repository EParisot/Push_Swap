/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/30 19:32:21 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

static void	vss1(t_list **lst_a)
{
	ra(lst_a);
	ft_printf("ra\n");
	if (lastval(*lst_a) > blastval(*lst_a))
	{
		sa(lst_a);
		ft_printf("sa\n");
	}
}

static void	vss2(t_list **lst_a, int min)
{
	if (*((int*)(*lst_a)->content) == min)
	{
		rra(lst_a);
		ft_printf("rra\n");
	}
	else
	{
		sa(lst_a);
		ft_printf("sa\n");
	}
}

static void	vss3(t_list **lst_a)
{
	rra(lst_a);
	ft_printf("rra\n");
	if (lastval(*lst_a) > blastval(*lst_a))
	{
		sa(lst_a);
		ft_printf("sa\n");
	}
}

void		very_small_sort(t_list **lst_a)
{
	int		max;
	int		min;

	max = ft_lstmax(*lst_a);
	min = ft_lstmin(*lst_a);
	if (!io(*lst_a))
	{
		if (lastval(*lst_a) == max)
			vss1(lst_a);
		else if (lastval(*lst_a) != min)
			vss2(lst_a, min);
		else
			vss3(lst_a);
	}
}
