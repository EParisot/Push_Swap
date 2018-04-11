/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:32:15 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/11 17:22:56 by eparisot         ###   ########.fr       */
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

static void		quick_b(t_list **lst_a, t_list **lst_b)
{
	int		c;
	int		med;

	while (!iro(*lst_b))
	{
		med = ft_lstmin(*lst_b) + ((ft_lstmax(*lst_b) - ft_lstmin(*lst_b)) / 2);
		c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
		while (c)
			if (lastval(*lst_b) > med)
			{
				pa(*lst_a, *lst_b);
				ft_printf("pa\n");
				c--;
			}
			else
			{
				rb(lst_b);
				ft_printf("rb\n");
			}
	}
	while ((*lst_b)->content)
	{
		pa(*lst_a, *lst_b);
		ft_printf("pa\n");
	}
}

static void		select_a(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;

	c = (ft_lstcount(*lst_a) - hmb(*lst_a, med)) / 2;
	while (c)
		if (lastval(*lst_a) == ft_lstmax(*lst_a))
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			c--;
		}
		else if (isinhalf(*lst_a, ft_lstmax(*lst_a)) >= 0)
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

static void		quick_a1(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;

	med = med + ((ft_lstmax(*lst_a) - med) / 2);
	c = ft_lstcount(*lst_a) - hmb(*lst_a, med);
	while (c)
		if (lastval(*lst_a) > med)
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			c--;
		}
		else if (isinhalf(*lst_a, ft_lstmax(*lst_a)) >= 0)
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

static void		quick_a2(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;
	int		tmp;

	tmp = med;
	med = med + ((ft_lstmax(*lst_a) - med) / 4);
	c = ft_lstcount(*lst_a) - hmb(*lst_a, med);
	while (c)
		if (lastval(*lst_a) > med)
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			c--;
		}
		else if (isinhalf(*lst_a, ft_lstmax(*lst_a)) >= 0)
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

static void		select_a1(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;

	c = ft_lstcount(*lst_a) - hmb(*lst_a, med);
	while (c)
		if (lastval(*lst_a) == ft_lstmax(*lst_a))
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			c--;
		}
		else if (isinhalf(*lst_a, ft_lstmax(*lst_a)) >= 0)
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

static void		quick_a1b(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;

	med = med - ((med - ft_lstmin(*lst_a)) / 4);
	c = ft_lstcount(*lst_a) - hmb(*lst_a, med);
	while (c)
		if (lastval(*lst_a) > med)
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			c--;
		}
		else if (isinhalf(*lst_a, ft_lstmax(*lst_a)) >= 0)
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

static void		quick_a2b(t_list **lst_a, t_list **lst_b, int med)
{
	int		c;

	med = med - ((med - ft_lstmin(*lst_a)) / 2);
	c = ft_lstcount(*lst_a) - hmb(*lst_a, med);
	while (c)
		if (lastval(*lst_a) > med)
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			c--;
		}
		else if (isinhalf(*lst_a, ft_lstmax(*lst_a)) >= 0)
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

static void		select_a2(t_list **lst_a, t_list **lst_b)
{
	int		c;

	c = ft_lstcount(*lst_a);
	while (c)
		if (lastval(*lst_a) == ft_lstmax(*lst_a))
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			c--;
		}
		else if (isinhalf(*lst_a, ft_lstmax(*lst_a)) >= 0)
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

static void		select_b(t_list **lst_a, t_list **lst_b)
{
	int		c;

	c = ft_lstcount(*lst_b);
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

void			sort_ter(t_list **lst_a, t_list **lst_b)
{
	int		i;
	int		med;

	i = 0;
	quick_a(lst_a, lst_b);
	quick_b(lst_a, lst_b);
	med = ft_lstmin(*lst_a) + ((ft_lstmax(*lst_a) - ft_lstmin(*lst_a)) / 2);
	select_a(lst_a, lst_b, med);
	quick_a1(lst_a, lst_b, med);
	quick_a2(lst_a, lst_b, med);
	select_a1(lst_a, lst_b, med);
	quick_a1b(lst_a, lst_b, med);
	quick_a2b(lst_a, lst_b, med);
	select_a2(lst_a, lst_b);
	select_b(lst_a, lst_b);
}
