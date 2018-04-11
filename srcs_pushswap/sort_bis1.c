/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:32:15 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/11 19:39:52 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

void		quick_a(t_list **lst_a, t_list **lst_b)
{
	int		c;
	int		med;

	while (!io(*lst_a))
	{
		med = ft_lstmin(*lst_a) + ((ft_lstmax(*lst_a) - ft_lstmin(*lst_a)) / 2);
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
	}
}

void		select_b1(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;

	c = (ft_lstcount(*lst_b) - hmb(*lst_b, med)) / 2;
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

void		quick_b1(t_list **lst_a, t_list **lst_b, int med, int i)
{
	med = med + ((ft_lstmax(*lst_b) - med) / 2);
	while ((ft_lstcount(*lst_b) - hmb(*lst_b, med)) / 2)
		if (lastval(*lst_b) > med)
		{
			pa(*lst_a, *lst_b);
			ft_printf("pa\n");
			i++;
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
	while (i--)
	{
		pb(*lst_a, *lst_b);
		ft_printf("pb\n");
	}
}

int		quick_b1a(t_list **lst_a, t_list **lst_b, int med, int i)
{
	med = med + ((ft_lstmax(*lst_b) - med) / 2);
	while ((ft_lstcount(*lst_b) - hmb(*lst_b, med)) / 2)
		if (lastval(*lst_b) > med)
		{
			pa(*lst_a, *lst_b);
			ft_printf("pa\n");
			i++;
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
	return (i);
}

int		quick_b1b(t_list **lst_a, t_list **lst_b, int med, int i)
{
	med = med + ((ft_lstmax(*lst_b) - med) / 4);
	while ((ft_lstcount(*lst_b) - hmb(*lst_b, med)) / 2)
		if (lastval(*lst_b) > med)
		{
			pa(*lst_a, *lst_b);
			ft_printf("pa\n");
			i++;
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
	return (i);
}
