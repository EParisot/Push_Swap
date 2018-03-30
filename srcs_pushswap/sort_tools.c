/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/30 20:34:16 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

void	split1(t_list **lst_a, t_list **lst_b, int med)
{
	int		min;
	int		max;
	int		c;

	while ((int*)(*lst_a)->content)
	{
		min = ft_lstmin(*lst_a);
		max = ft_lstmax(*lst_a);
		med = min + ((max - min) / 2);
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
				rra(lst_a);
				ft_printf("rra\n");
			}
	}
}

void	sort1(t_list **lst_a, t_list **lst_b, int med)
{
	int		max;
	int		c;

	max = ft_lstmax(*lst_b);
	med = ft_lstmin(*lst_b) + ((max - ft_lstmin(*lst_b)) / 2);
	c = ft_lstcount(*lst_b) - hmb(*lst_b, med) + 1;
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

int		split2(t_list **lst_a, t_list **lst_b)
{
	int		min;
	int		max;
	int		c;
	int		med;

	min = ft_lstmin(*lst_b);
	med = min + ((ft_lstmax(*lst_b) - min) / 2);
	c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
	max = 0;
	while (c && !iro(*lst_b))
		if (lastval(*lst_b) >= med)
		{
			pa(*lst_a, *lst_b);
			ft_printf("pa\n");
			c--;
			max++;
		}
		else
		{
			rrb(lst_b);
			ft_printf("rrb\n");
		}
	return (max);
}

int		split2bis(t_list **lst_a, t_list **lst_b, int max)
{
	int		min;
	int		med;
	int		c;

	min = ft_lstmin(*lst_b);
	med = min + ((ft_lstmax(*lst_b) - min) / 2);
	c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
	while (c && !iro(*lst_b))
		if (lastval(*lst_b) >= med)
		{
			pa(*lst_a, *lst_b);
			ft_printf("pa\n");
			c--;
			max++;
		}
		else
		{
			rrb(lst_b);
			ft_printf("rrb\n");
		}
		return (max);
}

void	merge2(t_list **lst_a, t_list **lst_b, int med)
{
	int		max;
	int		c;

	max = ft_lstmax(*lst_b);
	med = ft_lstmin(*lst_b) + ((max - ft_lstmin(*lst_b)) / 2);
	c = ft_lstcount(*lst_b);
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
