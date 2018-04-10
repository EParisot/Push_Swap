/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:32:15 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/10 20:44:11 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

static void sort1(t_list **lst_a, t_list **lst_b, int med, int n)
{
	int		c;
	int		i;
	int		j;

	c = 0;
	i = 0;
	j = 0;
	if (!io(*lst_a))
	{
		c = hmb(*lst_a, med);
		while (c)
			if (lastval(*lst_a) <= med)
			{
				pb(*lst_a, *lst_b);
				ft_printf("pb\n");
				c--;
			}
			else
			{
				ra(lst_a);
				ft_printf("ra\n");
			}
		med = ft_lstmin(*lst_a) + ((ft_lstmax(*lst_a) - ft_lstmin(*lst_a)) / 2);
	}
	if (!io(*lst_a))
		sort1(lst_a, lst_b, med, ++n);
	c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
	if (c <= 10)
	{
		while (c)
			if (lastval(*lst_b) == ft_lstmax(*lst_b))
			{
				pa(*lst_a, *lst_b);
				ft_printf("pa\n");
				c--;
			}
			else if (isinhalf(*lst_b, ft_lstmax(*lst_b)) >= 0)
			{
				rrb(lst_b);
				ft_printf("rrb\n");
			}
			else
			{
				rb(lst_b);
				ft_printf("rb\n");
			}
	}
	else
	{
		med = med + ((med / n) / 2);
		c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
		while (c)
			if (lastval(*lst_b) > med)
			{
				pa(*lst_a, *lst_b);
				ft_printf("pa\n");
				c--;
				i++;
			}
			else
			{
				rb(lst_b);
				ft_printf("rb\n");
				j++;
			}
		while (j)
		{
			rrb(lst_b);
			ft_printf("rrb\n");
			j--;
		}
		while (i)
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			i--;
		}
		sort1(lst_a, lst_b, med, n);
	}
}

void sort_bis(t_list **lst_a, t_list **lst_b)
{
	int		med;

	med = ft_lstmin(*lst_a) + ((ft_lstmax(*lst_a) - ft_lstmin(*lst_a)) / 2);
	sort1(lst_a, lst_b, med, 1);
}
