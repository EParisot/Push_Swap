/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/28 22:42:00 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"
/*
static int	io(t_list *lst_a)
{
	while (lst_a->next)
	{
		if ((*(int*)lst_a->next->content) > (*(int*)lst_a->content))
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

static int	iro(t_list *lst_a)
{
	while (lst_a->next)
	{
		if ((*(int*)lst_a->next->content) < (*(int*)lst_a->content))
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

static int	blastval(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (*((int*)lst->content));
}
*/
static int	lastval(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (*((int*)lst->content));
}
/*
static int	isinhalf(t_list *lst, int nb)
{
	int		i;
	int		c;
	int		k;

	i = 0;
	k = 0;
	c = ft_lstcount(lst);
	while (lst->content && i <= c / 2)
	{
		if (*((int*)lst->content) == nb)
			return (i);
		lst = lst->next;
		i++;
	}
	k = i;
	while (lst)
	{
		if (*((int*)lst->content) == nb)
			return (k - c);
		lst = lst->next;
		k++;
	}
	return (k - c);
}

static void	select_sort(t_list **lst_a, t_list **lst_b)
{
	int		min;
	int		max;
	int		i;

	min = ft_lstmin(*lst_a);
	max = ft_lstmax(*lst_a);
	i = 0;
	while ((*lst_a)->content != NULL)
	{
		if (lastval(*lst_a) == min || lastval(*lst_a) == max)
		{
			if (lastval(*lst_a) == max)
			{
				pb(*lst_a, *lst_b);
				ft_printf("pb\n");
				rb(lst_b);
				ft_printf("rb\n");
				i++;
			}
			else if (lastval(*lst_a) == min)
			{
				pb(*lst_a, *lst_b);
				ft_printf("pb\n");
			}
			min = ft_lstmin(*lst_a);
			max = ft_lstmax(*lst_a);
		}
		else if (*((int*)(*lst_a)->content) == min || \
		*((int*)(*lst_a)->content) == max)
		{
			if (*((int*)(*lst_a)->content) == max)
			{
				rra(lst_a);
				ft_printf("rra\n");
				pb(*lst_a, *lst_b);
				ft_printf("pb\n");
				rb(lst_b);
				ft_printf("rb\n");
				i++;
			}
			else if (*((int*)(*lst_a)->content) == min)
			{
				rra(lst_a);
				ft_printf("rra\n");
				pb(*lst_a, *lst_b);
				ft_printf("pb\n");
			}
			min = ft_lstmin(*lst_a);
			max = ft_lstmax(*lst_a);
		}
		else if (isinhalf(*lst_a, min) > 0 && isinhalf(*lst_a, max) > 0)
		{
			rra(lst_a);
			ft_printf("rra\n");
		}
		else if (isinhalf(*lst_a, min) < 0 && isinhalf(*lst_a, max) < 0)
		{
			ra(lst_a);
			ft_printf("ra\n");
		}
		else if (isinhalf(*lst_a, min) > 0 && isinhalf(*lst_a, max) < 0)
		{
			if (isinhalf(*lst_a, min) < -1 * isinhalf(*lst_a, max))
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
		else if (isinhalf(*lst_a, min) < 0 && isinhalf(*lst_a, max) > 0)
		{
			if (isinhalf(*lst_a, min) * -1 < isinhalf(*lst_a, max))
			{
				ra(lst_a);
				ft_printf("ra\n");
			}
			else
			{
				rra(lst_a);
				ft_printf("rra\n");
			}
		}
	}
	if (isinhalf(*lst_b, ft_lstmax(*lst_b)))
		while (i)
		{
			rrb(lst_b);
			ft_printf("rrb\n");
			i--;
		}
	else
		while (ft_lstcount(*lst_b) - i)
		{
			rb(lst_b);
			ft_printf("rb\n");
			i++;
		}
	while ((*lst_b)->content)
	{
		pa(*lst_a, *lst_b);
		ft_printf("pa\n");
	}
}
*/

static void	sort(t_list **lst_a, t_list **lst_b)
{
	int		min;
	int		max;
	int		med;
	int		c;

	med = 0;
	while (ft_lstcount(*lst_a) > 1)
	{
		min = ft_lstmin(*lst_a);
		max = ft_lstmax(*lst_a);
		med += min + ((max - min) / 2);
		c = ft_lstcount(*lst_a);
		while (c)
		{
			if (lastval(*lst_a) <= med)
			{
				pb(*lst_a, *lst_b);
				ft_printf("pb\n");
			}
			rra(lst_a);
			ft_printf("rra\n");
			c--;
		}
	}
}

void		pushswap(t_list **lst_a)
{
	t_list	*lst_b;

	lst_b = ft_lstnew(NULL, sizeof(int));
	sort(lst_a, &lst_b);
	ft_printf("\n");
	ft_lstdel(&lst_b, del);
}
