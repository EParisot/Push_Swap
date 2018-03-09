/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:42:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/09 21:36:12 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	lst_print(t_list *lst, t_list *tmp)
{
	tmp = lst;
	while (lst)
	{
		ft_printf("%d\n", *((int*)lst->content));
		lst = lst->next;
	}
	lst = tmp;
}

void	checker(t_list *lst_a)
{
	t_list *tmp;

	if((tmp = (t_list*)malloc(sizeof(t_list*))) == NULL)
		return ;
	lst_print(lst_a, tmp);
	free(tmp);
}
