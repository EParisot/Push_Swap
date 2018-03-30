/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/30 18:45:56 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

static int	io(t_list *lst)
{
	while (lst->next)
	{
		if (*((int*)lst->next->content) > *((int*)lst->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	iro(t_list *lst)
{
	while (lst->next)
	{
		if (*((int*)lst->next->content) < *((int*)lst->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	lastval(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (*((int*)lst->content));
}

static int	blastval(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (*((int*)lst->content));
}

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

static int	hmb(t_list *lst, int nb)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (*((int*)lst->content) <= nb)
			count++;
		lst = lst->next;
	}
	return (count);
}

static void	sort(t_list **lst_a, t_list **lst_b)
{
	int		min;
	int		max;
	int		med;
	int		c;

	med = 0;
	while ((int*)(*lst_a)->content)
	{
		min = ft_lstmin(*lst_a);
		max = ft_lstmax(*lst_a);
		med = min + ((max - min) / 2);
		c = hmb(*lst_a, med);
		while (c)
		{
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
	min = ft_lstmin(*lst_b);
	max = ft_lstmax(*lst_b);
	med = min + ((max - min) / 2);
	c = ft_lstcount(*lst_b) - hmb(*lst_b, med) + 1;
	while (c)
	{
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
	min = ft_lstmin(*lst_b);
	med = min + ((ft_lstmax(*lst_b) - min) / 2);
	c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
	max = 0;
	while (c && !iro(*lst_b))
	{
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
	}
	med = min + ((ft_lstmax(*lst_b) - min) / 2);
	c = ft_lstcount(*lst_b) - hmb(*lst_b, med);
	while (c && !iro(*lst_b))
	{
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
	}
	while (max)
	{
		pb(*lst_a, *lst_b);
		ft_printf("pb\n");
		if (lastval(*lst_b) < blastval(*lst_b))
		{
			sb(lst_b);
			ft_printf("sb\n");
		}
		max--;
	}
	min = ft_lstmin(*lst_b);
	max = ft_lstmax(*lst_b);
	med = min + ((max - min) / 2);
	c = ft_lstcount(*lst_b);
	while (c)
	{
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
}

static void		small_sort(t_list **lst_a, t_list **lst_b)
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

static void	very_small_sort(t_list **lst_a)
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

void		pushswap(t_list **lst_a)
{
	t_list	*lst_b;

	lst_b = ft_lstnew(NULL, sizeof(int));
	if (ft_lstcount(*lst_a) <= 3)
		very_small_sort(lst_a);
	else if (ft_lstcount(*lst_a) <= 5)
		small_sort(lst_a, &lst_b);
	else
		sort(lst_a, &lst_b);
	ft_printf("\n");
	ft_lstdel(&lst_b, del);
}
