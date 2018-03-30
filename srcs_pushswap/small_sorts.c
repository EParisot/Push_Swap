/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/30 19:02:45 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

void		small_sort(t_list **lst_a, t_list **lst_b)
{
	int		c;
	int		min;
	int		max;
	int		med;

	min = ft_lstmin(*lst_a);
	max = ft_lstmax(*lst_a);
	med = min + ((max - min) / 2);
	c = hmb(*lst_a, med);
	while (c && !io(*lst_a))
	{
		if (lastval(*lst_a) == min)
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			min = ft_lstmin(*lst_a);
			c--;
		}
		else if (isinhalf(*lst_a, min) >= 0)
		{
			rra(lst_a);
			ft_printf("rra\n");
		}
		else
		{
			ra(lst_a);
			ft_printf("ra\n");
		}
	}
	if (lastval(*lst_a) > blastval(*lst_a))
	{
		sa(lst_a);
		ft_printf("sa\n");
	}
	c = ft_lstcount(*lst_b);
	while (c)
	{
		pa(*lst_a, *lst_b);
		ft_printf("pa\n");
		c--;
	}
}

void	very_small_sort(t_list **lst_a)
{
	int		max;
	int		min;

	if (!io(*lst_a))
	{
		max = ft_lstmax(*lst_a);
		min = ft_lstmin(*lst_a);
		if (lastval(*lst_a) == max)
		{
			ra(lst_a);
			ft_printf("ra\n");
			if (lastval(*lst_a) > blastval(*lst_a))
			{
				sa(lst_a);
				ft_printf("sa\n");
			}
		}
		else if (lastval(*lst_a) != min)
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
		else
		{
			rra(lst_a);
			ft_printf("rra\n");
			if (lastval(*lst_a) > blastval(*lst_a))
			{
				sa(lst_a);
				ft_printf("sa\n");
			}
		}
	}
}
