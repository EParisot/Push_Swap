/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/30 19:50:45 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

static void	ss1(t_list **lst_a, t_list **lst_b, int c)
{
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

void		small_sort(t_list **lst_a, t_list **lst_b)
{
	int		c;
	int		min;

	min = ft_lstmin(*lst_a);
	c = hmb(*lst_a, min + ((ft_lstmax(*lst_a) - min) / 2));
	while (c && !io(*lst_a))
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
	ss1(lst_a, lst_b, c);
}
