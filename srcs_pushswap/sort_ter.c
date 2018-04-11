/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:32:15 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/11 14:27:44 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

static void		quick_a(t_list **lst_a, t_list **lst_b)
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
/*
static void		select_b1(t_list **lst_a, t_list **lst_b, int med)
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

static void		quick_b1(t_list **lst_a, t_list **lst_b, int med, int i)
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

static int		quick_b1a(t_list **lst_a, t_list **lst_b, int med, int i)
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

static int		quick_b1b(t_list **lst_a, t_list **lst_b, int med, int i)
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

static void		quick_b1c(t_list **lst_a, t_list **lst_b, int med, int i)
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

static void		select_b2(t_list **lst_a, t_list **lst_b, int med)
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

static void		quick_b2(t_list **lst_a, t_list **lst_b, int med, int i)
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

static void		select_b3(t_list **lst_a, t_list **lst_b)
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
*/
static int			sort_ter_aux(t_list **lst_a, t_list **lst_b, int med)
{
	med = ft_lstmin(*lst_a) + ((ft_lstmax(*lst_a) - ft_lstmin(*lst_a)) / 2);
	quick_a(lst_a, lst_b);
	//select_b1(lst_a, lst_b, med);
	return (med);
}

void			sort_ter(t_list **lst_a, t_list **lst_b)
{
	int		med;
	int		i;

	i = 0;
	med = sort_ter_aux(lst_a, lst_b, 0);/*
	if (ft_lstcount(*lst_a) + ft_lstcount(*lst_b) > 101)
	{
		i = quick_b1a(lst_a, lst_b, med, 0);
		i = quick_b1b(lst_a, lst_b, med, i);
		quick_b1c(lst_a, lst_b, med, i);
	}
	else
		quick_b1(lst_a, lst_b, med, 0);
	select_b2(lst_a, lst_b, med);
	quick_b2(lst_a, lst_b, med, 0);
	med = ft_lstmin(*lst_b) + ((ft_lstmax(*lst_b) - ft_lstmin(*lst_b)) / 2);
	if (ft_lstcount(*lst_a) + ft_lstcount(*lst_b) > 101)
	{
		i = quick_b1a(lst_a, lst_b, med, 0);
		i = quick_b1b(lst_a, lst_b, med, i);
		quick_b1c(lst_a, lst_b, med, i);
	}
	else
		quick_b1(lst_a, lst_b, med, 0);
	select_b3(lst_a, lst_b);*/
}
