/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:16:28 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/15 20:23:20 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_list **lst_a)
{
	t_list	*tmp;
	int		*mem;

	tmp = *lst_a;
	mem = NULL;
	if (ft_lstcount(*lst_a) > 1)
	{
		while ((*lst_a)->next->next)
			*lst_a = (*lst_a)->next;
		mem = (int*)(*lst_a)->content;
		(*lst_a)->content = (*lst_a)->next->content;
		(*lst_a)->next->content = mem;
		*lst_a = tmp;
	}
}

void	sb(t_list **lst_b)
{
	t_list	*tmp;
	int		*mem;

	tmp = *lst_b;
	mem = NULL;
	if (ft_lstcount(*lst_b) > 1)
	{
		while ((*lst_b)->next->next)
			*lst_b = (*lst_b)->next;
		mem = (int*)(*lst_b)->content;
		(*lst_b)->content = (*lst_b)->next->content;
		(*lst_b)->next->content = mem;
		*lst_b = tmp;
	}
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	sa(lst_a);
	sb(lst_b);
}

void	pa(t_list *lsta, t_list *lst_b)
{
	while (lst_b && ft_lstcount(lst_b) && lst_b->content != NULL)
	{
		if (lst_b->next && (lst_b->next)->next == NULL)
		{
			if (lsta->content == NULL)
				lsta->content = (lst_b->next)->content;
			else
			{
				ft_lstaddend(&lsta, ft_lstnew(((int*)lst_b->next->content), 4));
				free(lst_b->next->content);
			}
			free(lst_b->next);
			lst_b->next = NULL;
		}
		else if (lst_b->next == NULL)
		{
			if (lsta->content == NULL)
				lsta->content = lst_b->content;
			else
				ft_lstaddend(&lsta, ft_lstnew(((int *)lst_b->content), 4));
			free(lst_b->content);
			lst_b->content = NULL;
		}
		lst_b = lst_b->next;
	}
}

void	pb(t_list *lst_a, t_list *lstb)
{
	while (lst_a && ft_lstcount(lst_a) && lst_a->content != NULL)
	{
		if (lst_a->next && (lst_a->next)->next == NULL)
		{
			if (lstb->content == NULL)
				lstb->content = (lst_a->next)->content;
			else
			{
				ft_lstaddend(&lstb, ft_lstnew(((int*)lst_a->next->content), 4));
				free(lst_a->next->content);
			}
			free(lst_a->next);
			lst_a->next = NULL;
		}
		else if (lst_a->next == NULL)
		{
			if (lstb->content == NULL)
				lstb->content = lst_a->content;
			else
				ft_lstaddend(&lstb, ft_lstnew(((int *)lst_a->content), 4));
			free(lst_a->content);
			lst_a->content = NULL;
		}
		lst_a = lst_a->next;
	}
}
