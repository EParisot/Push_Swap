/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:16:28 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/14 17:25:55 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rra(t_list **lst_a)
{
	t_list *tmp;

	tmp = *lst_a;
	if (ft_lstcount(*lst_a) > 1)
	{
		while ((tmp->next)->next)
			tmp = tmp->next;
		ft_lstadd(lst_a, ft_lstnew((tmp->next)->content, sizeof(int)));
		tmp->next = NULL;
	}
	return ;
}

void	rrb(t_list **lst_b)
{
	t_list *tmp;

	tmp = *lst_b;
	if (ft_lstcount(*lst_b) > 1)
	{
		while ((tmp->next)->next)
			tmp = tmp->next;
		ft_lstadd(lst_b, ft_lstnew((tmp->next)->content, sizeof(int)));
		tmp->next = NULL;
	}
	return ;
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a);
	rrb(lst_b);
	return ;
}
