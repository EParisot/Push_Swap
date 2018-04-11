/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:32:15 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/11 19:46:06 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

void		quick_b1c(t_list **lst_a, t_list **lst_b, int med, int i)
{
	med = med + ((ft_lstmax(*lst_b) - med) / 8);
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

void		select_b2(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;

	c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
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

void		quick_b2(t_list **lst_a, t_list **lst_b, int med, int i)
{
	while (!iro(*lst_b))
		while (ft_lstcount(*lst_b) - hmb(*lst_b, (med = ft_lstmin(*lst_b) + \
		((ft_lstmax(*lst_b) - ft_lstmin(*lst_b)) / 2))) && !iro(*lst_b))
			if (lastval(*lst_b) > med)
			{
				pa(*lst_a, *lst_b);
				ft_printf("pa\n");
				i++;
			}
			else if (isinhalf(*lst_b, ft_lstmax(*lst_b)) >= 0 && \
			ft_lstcount(*lst_a) + ft_lstcount(*lst_b) > 101)
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

void		select_b3(t_list **lst_a, t_list **lst_b)
{
	int		c;
	int		max;

	c = ft_lstcount(*lst_b);
	max = ft_lstmax(*lst_b);
	while (c)
		if (lastval(*lst_b) == max)
		{
			pa(*lst_a, *lst_b);
			ft_printf("pa\n");
			max = ft_lstmax(*lst_b);
			c--;
		}
		else if (isinhalf(*lst_b, max) >= 0)
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

