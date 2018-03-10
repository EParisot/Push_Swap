/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:16:28 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/10 18:31:27 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_list *lst_a)
{
	size_t	len;

	len = 0;
	if ((len = ft_lstcount(lst_a)) > 1)
		ft_lstswap_val(lst_a, len - 2, len - 1);
	return ;
}

void	sb(t_list *lst_b)
{
	(void)lst_b;
	return ;
}

void	ss(t_list *lst_a, t_list *lst_b)
{
	(void)lst_a;
	(void)lst_b;
	return ;
}

void	pa(t_list *lst_a, t_list *lst_b)
{
	(void)lst_a;
	(void)lst_b;
	return ;
}

void	pb(t_list *lst_a, t_list *lst_b)
{
	(void)lst_a;
	(void)lst_b;
	return ;
}
