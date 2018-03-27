/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/27 20:35:37 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

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
/*
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
*
*/
static int	isinhalf(t_list *lst, int nb)
{
	int		i;
	int		c;

	i = 0;
	c = ft_lstcount(lst);
	while (lst->content && i <= c / 2)
	{
		if (*((int*)lst->content) == nb)
			return (1);
		lst = lst->next;
		i++;
	}
	return (0);
}

static int	lastval(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (*((int*)lst->content));
}
/*
static int	blastval(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (*((int*)lst->content));
}
*/
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
		if (lastval(*lst_a) <= min || lastval(*lst_a) == max)
		{
			if (lastval(*lst_a) == max)
			{
				pb(*lst_a, *lst_b);
				ft_printf("pb\n");
				rb(lst_b);
				ft_printf("rb\n");
				i++;
			}
			else
			{
				pb(*lst_a, *lst_b);
				ft_printf("pb\n");
			}
			min = ft_lstmin(*lst_a);
			max = ft_lstmax(*lst_a);
		}
		else if (isinhalf(*lst_a, min))
		{
			rra(lst_a);
			ft_printf("rra\n");
		}
		else
		{
			ra(lst_a);
			ft_printf("ra\n");
		}
		//if (io(*lst_a))
		//break;
	}
	while (i)
	{
		rrb(lst_b);
		ft_printf("rrb\n");
		i--;
	}
	while ((*lst_b)->content)
	{
		pa(*lst_a, *lst_b);
		ft_printf("pa\n");
	}
}
/*
static void	sort2(t_list **lsta, t_list **lstb)
{
	while (!io(*lsta) && !io(*lstb))
	{
		if (lastval(*lsta) > blastval(*lsta) && lastval(*lsta) != ft_lstmax(*lsta))
		{
			sa(lsta);
			ft_printf("sa\n");
		}
		if (lastval(*lstb) > blastval(*lstb) && lastval(*lstb) != ft_lstmax(*lstb))
		{
			sb(lstb);
			ft_printf("sb\n");
		}
		if (io(*lsta) || io(*lstb))
			break;
		rrr(lsta, lstb);
		ft_printf("rrr\n");
	}
	while (!(io(*lsta) && io(*lstb)))
	{
		if (!io(*lsta))
		{
			if (lastval(*lsta) > blastval(*lsta) && lastval(*lsta) != ft_lstmax(*lsta))
			{
				sa(lsta);
				ft_printf("sa\n");
			}
			if (io(*lsta))
				break;
			rra(lsta);
			ft_printf("rra\n");
		}
		if (lastval(*lstb) > blastval(*lstb) && lastval(*lstb) != ft_lstmax(*lstb))
		{
			if (!io(*lstb))
			{
				sb(lstb);
				ft_printf("sb\n");
			}
			if (io(*lstb))
				break;
			rrb(lstb);
			ft_printf("rrb\n");
		}
	}
}

static void	sort(t_list **lst_a, t_list ** lst_b)
{
	int		mid;
	//int		med;

	mid = (int)ft_lstcount(*lst_a) / 2;
	//med = (int)(ft_lstmax(*lst_a) - (int)ft_lstmin(*lst_a)) / 2;
	while (mid)
	{
		//if (lastval(*lst_a) <= med)
		//{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			mid--;
		//}
		//else
		//{
		//	rra(lst_a);
		//	ft_printf("rra\n");
		//}
	}
	sort2(lst_a, lst_b);
	while ((*lst_b)->content)
	{
		if (lastval(*lst_a) > lastval(*lst_b))
		{
			pa(*lst_a, *lst_b);
			ft_printf("pa\n");
		}
		rra(lst_a);
		ft_printf("rra\n");
	}
}
*/
void		pushswap(t_list **lst_a)
{
	t_list	*lst_b;

	lst_b = ft_lstnew(NULL, sizeof(int));
	while (!io(*lst_a) || lst_b->content)
	{
		select_sort(lst_a, &lst_b);
		//sort(lst_a, &lst_b);
	}
	ft_printf("\n");
	ft_lstdel(&lst_b, del);
}
