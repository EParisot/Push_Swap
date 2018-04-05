/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/05 11:07:10 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

int	io(t_list *lst)
{
	while (lst->next)
	{
		if (*((int*)lst->next->content) > *((int*)lst->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	iro(t_list *lst)
{
	while (lst->next)
	{
		if (*((int*)lst->next->content) < *((int*)lst->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	lastval(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (*((int*)lst->content));
}

int	blastval(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (*((int*)lst->content));
}

int	isinhalf(t_list *lst, int nb)
{
	int		i;
	int		c;
	int		k;

	i = 0;
	k = 0;
	c = ft_lstcount(lst);
	while (lst->content && i <= c / 2)
	{
		if (*((int*)lst->content) == nb)
			return (i);
		lst = lst->next;
		i++;
	}
	k = i;
	while (lst)
	{
		if (*((int*)lst->content) == nb)
			return (k - c);
		lst = lst->next;
		k++;
	}
	return (k - c);
}

int	hmb(t_list *lst, int nb)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (*((int*)lst->content) <= nb)
			count++;
		lst = lst->next;
	}
	return (count);
}
