/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/22 11:18:17 by eparisot         ###   ########.fr       */
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

void		select_sort(t_list **lst_a, t_list **lst_b)
{
	int		min;

	min = ft_lstmin(*lst_a);
	while ((*lst_a)->content && *((int*)(*lst_a)->content))
	{
		if (*((int*)(*lst_a)->content) <= min)
		{
			rra(lst_a);
			ft_printf("rra\n");
			pb(*lst_a, *lst_b);
			ft_printf("pb\n");
			min = ft_lstmin(*lst_a);
		}
		ra(lst_a);
		ft_printf("ra\n");
		if (io(*lst_a) && !(*lst_b)->content)
			break;
	}
	while ((*lst_b)->content && *((int*)(*lst_b)->content))
	{
		pa(*lst_a, *lst_b);
		ft_printf("pa\n");
	}
}

void		pushswap(t_list **lst_a)
{
	t_list	*lst_b;

	lst_b = ft_lstnew(NULL, sizeof(int));
	while (!io(*lst_a))
	{
		select_sort(lst_a, &lst_b);
	}
	ft_printf("\n");
	ft_lstdel(&lst_b, del);
}
