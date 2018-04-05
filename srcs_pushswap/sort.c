/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/05 11:06:13 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

static void	split1(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;

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

static void	sort1(t_list **lst_a, t_list **lst_b, int med)
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

static int	split2(t_list **lst_a, t_list **lst_b, int max, int c)
{
	int		med;

	while (!iro(*lst_b))
	{
		med = ft_lstmin(*lst_b) + ((ft_lstmax(*lst_b) - ft_lstmin(*lst_b)) / 2);
		c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
		while (c && !iro(*lst_b))
			if (lastval(*lst_b) >= med)
			{
				pa(*lst_a, *lst_b);
				ft_printf("pa\n");
				max++;
				c--;
			}
			else
			{
				rb(lst_b);
				ft_printf("rb\n");
			}
	}
	return (max);
}

static void	sort2(t_list **lst_a, t_list **lst_b, int med)
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

void		sort(t_list **lst_a, t_list **lst_b)
{
	int		max;

	split1(lst_a, lst_b, 0);
	sort1(lst_a, lst_b, 0);
	max = split2(lst_a, lst_b, 0, 0);
	while (max)
	{
		pb(*lst_a, *lst_b);
		ft_printf("pb\n");
		max--;
	}
	sort2(lst_a, lst_b, 0);
}
