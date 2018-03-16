/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:16:28 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/16 14:25:45 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_list **lst_a)
{
	t_list	*tmp;

	tmp = *lst_a;
	if (ft_lstcount(*lst_a) > 1)
	{
		while ((tmp->next)->next)
			tmp = tmp->next;
		ft_lstadd(lst_a, ft_lstnew((tmp->next)->content, sizeof(int)));
		free(tmp->next->content);
		tmp->next->content = NULL;
		free(tmp->next);
		tmp->next = NULL;
	}
	return ;
}

void	rb(t_list **lst_b)
{
	t_list *tmp;

	tmp = *lst_b;
	if (ft_lstcount(*lst_b) > 1)
	{
		while ((tmp->next)->next)
			tmp = tmp->next;
		ft_lstadd(lst_b, ft_lstnew((tmp->next)->content, sizeof(int)));
		free(tmp->next->content);
		tmp->next->content = NULL;
		free(tmp->next);
		tmp->next = NULL;
	}
	return ;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a);
	rb(lst_b);
	return ;
}
