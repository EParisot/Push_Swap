/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:16:28 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/16 14:41:42 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rra(t_list **lst_a)
{
	t_list	*tmp;

	tmp = *lst_a;
	if (ft_lstcount(*lst_a) > 1)
	{
		ft_lstaddend(lst_a, ft_lstnew(((tmp)->content), sizeof(int)));
		free(tmp->content);
		tmp->content = NULL;
		*lst_a = (*lst_a)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	rrb(t_list **lst_b)
{
	t_list	*tmp;

	tmp = *lst_b;
	if (ft_lstcount(*lst_b) > 1)
	{
		ft_lstaddend(lst_b, ft_lstnew(((tmp)->content), sizeof(int)));
		free(tmp->content);
		tmp->content = NULL;
		*lst_b = (*lst_b)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a);
	rra(lst_b);
}
