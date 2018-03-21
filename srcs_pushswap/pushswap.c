/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/21 19:00:07 by eparisot         ###   ########.fr       */
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

static int	*info(t_list *lst_a, int *info_tab)
{
	info_tab[0] = (int)ft_lstcount(lst_a);
	info_tab[1] = ft_lstmin(lst_a);
	info_tab[2] = ft_lstmax(lst_a);
	return (info_tab);
}

void		insert_sort(t_list **lst_a, t_list **lst_b, int *info_tab)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		min;

	tmp_a = *lst_a;
	tmp_b = *lst_b;
	min = info_tab[1];
	//
	//
	//
	//
}

void		pushswap(t_list **lst_a)
{
	t_list	*lst_b;
	int		*info_tab;

	if ((info_tab = (int*)malloc(3 * sizeof(int))) == NULL)
		return ;
	lst_b = ft_lstnew(NULL, sizeof(int));
	info_tab = info(*lst_a, info_tab);
	while (!io(*lst_a))
	{
		insert_sort(lst_a, &lst_b, info_tab);
	}
	ft_lstdel(&lst_b, del);
}
