/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:04:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/10 18:51:16 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_swap_val(t_list *lst, t_list *tmp, int i, int j)
{
	int		*mem1;
	int		*mem2;
	int		c;

	mem1 = NULL;
	mem2 = NULL;
	c = -1;
	while (++c < i && lst)
		lst = lst->next;
	mem1 = lst->content;
	lst = tmp;
	c = -1;
	while (++c < j && lst)
		lst = lst->next;
	mem2 = lst->content;
	lst->content = mem1;
	lst = tmp;
	c = -1;
	while (++c < i && lst)
		lst = lst->next;
	lst->content = mem2;
}

void		ft_lstswap_val(t_list *lst, int i, int j)
{
	size_t	len;
	t_list	*tmp;

	len = 0;
	tmp = ft_lstnew(NULL, sizeof(int));
	tmp = lst;
	if (ft_lstcount(lst) > (size_t)j && i < j)
		ft_swap_val(lst, tmp, i, j);
	lst = tmp;
	free(tmp);
	return ;
}
