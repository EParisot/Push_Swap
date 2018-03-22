/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/22 21:42:09 by eparisot         ###   ########.fr       */
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

static void	select_sort(t_list **lst_a, t_list **lst_b)
{
	int		min;

	min = ft_lstmin(*lst_a);
	while ((*lst_a)->content != NULL)
	{
		if (lastval(*lst_a) <= min)
		{
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			min = ft_lstmin(*lst_a);
		}
		if (isinhalf(*lst_a, min))
		{
			rra(lst_a);
			ft_printf("rra\n");
		}
		else
		{
			ra(lst_a);
			ft_printf("ra\n");
		}
		if (io(*lst_a) && (*lst_b)->content == NULL)
		break;
	}

}

void		pushswap(t_list **lst_a)
{
	t_list	*lst_b;

	lst_b = ft_lstnew(NULL, sizeof(int));
	while (!io(*lst_a) || lst_b->content)
	{
		select_sort(lst_a, &lst_b);
		while (lst_b->content)
		{
			pa(*lst_a, lst_b);
			ft_printf("pa\n");
		}
	}
	ft_printf("\n");
	ft_lstdel(&lst_b, del);
}
