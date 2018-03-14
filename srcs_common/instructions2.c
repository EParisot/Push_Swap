/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:16:28 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/14 17:05:55 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_list **lst_a)
{
	if (ft_lstcount(*lst_a) > 1)
	{
		ft_lstaddend(lst_a, ft_lstnew(((*lst_a)->content), sizeof(int)));
		*lst_a = (*lst_a)->next;
	}
	return ;
}

void	rb(t_list **lst_b)
{
	if (ft_lstcount(*lst_b) > 1)
	{
		ft_lstaddend(lst_b, ft_lstnew(((*lst_b)->content), sizeof(int)));
		*lst_b = (*lst_b)->next;
	}
	return ;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a);
	ra(lst_b);
	return ;
}
