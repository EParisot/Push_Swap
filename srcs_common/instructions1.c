/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:16:28 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/14 22:42:02 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_list **lst_a)
{
(void)*lst_a;
}

void	sb(t_list **lst_b)
{
(void)*lst_b;
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	sa(lst_a);
	sb(lst_b);
}

void	pa(t_list *lst_a, t_list *lst_b)
{
	if (ft_lstcount(lst_b) && lst_b->content != NULL)
		while (lst_b)
		{
			if (lst_b->next && (lst_b->next)->next == NULL)
			{
				if (lst_a->content == NULL)
					lst_a->content = (lst_b->next)->content;
				else
					ft_lstaddend(&lst_a, lst_b->next);
				lst_b->next = NULL;
			}
			else if (lst_b->next == NULL)
			{
				ft_lstaddend(&lst_a, ft_lstnew(((int *)lst_b->content), sizeof(int)));
				lst_b->content = NULL;
			}
			lst_b = lst_b->next;
		}
	return ;
}

void	pb(t_list *lst_a, t_list *lst_b)
{
	if (ft_lstcount(lst_a) && lst_a->content != NULL)
		while (lst_a)
		{
			if (lst_a->next && (lst_a->next)->next == NULL)
			{
				if (lst_b->content == NULL)
					lst_b->content = (lst_a->next)->content;
				else
					ft_lstaddend(&lst_b, lst_a->next);
				lst_a->next = NULL;
			}
			else if (lst_a->next == NULL)
			{
				ft_lstaddend(&lst_b, ft_lstnew(((int *)lst_a->content), sizeof(int)));
				lst_a->content = NULL;
			}
			lst_a = lst_a->next;
		}
	return ;
}
