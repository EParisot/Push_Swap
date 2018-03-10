/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:16:28 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/10 19:15:47 by eparisot         ###   ########.fr       */
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
	size_t	len;

	len = 0;
	if ((len = ft_lstcount(lst_b)) > 1)
		ft_lstswap_val(lst_b, len - 2, len - 1);
	return ;
}

void	ss(t_list *lst_a, t_list *lst_b)
{
	size_t	len;

	len = 0;
	if ((len = ft_lstcount(lst_a)) > 1)
		ft_lstswap_val(lst_a, len - 2, len - 1);
	if ((len = ft_lstcount(lst_b)) > 1)
		ft_lstswap_val(lst_b, len - 2, len - 1);
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
