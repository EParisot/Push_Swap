/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:32:15 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/11 19:41:34 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../srcs_common/common.h"

static int			sort_bis_aux(t_list **lst_a, t_list **lst_b, int med)
{
	med = ft_lstmin(*lst_a) + ((ft_lstmax(*lst_a) - ft_lstmin(*lst_a)) / 2);
	quick_a(lst_a, lst_b);
	select_b1(lst_a, lst_b, med);
	return (med);
}

void			sort_bis(t_list **lst_a, t_list **lst_b)
{
	int		med;
	int		i;

	i = 0;
	med = sort_bis_aux(lst_a, lst_b, 0);
	if (ft_lstcount(*lst_a) + ft_lstcount(*lst_b) > 101)
	{
		i = quick_b1a(lst_a, lst_b, med, 0);
		i = quick_b1b(lst_a, lst_b, med, i);
		quick_b1c(lst_a, lst_b, med, i);
	}
	else
		quick_b1(lst_a, lst_b, med, 0);
	select_b2(lst_a, lst_b, med);
	quick_b2(lst_a, lst_b, med, 0);
	med = ft_lstmin(*lst_b) + ((ft_lstmax(*lst_b) - ft_lstmin(*lst_b)) / 2);
	if (ft_lstcount(*lst_a) + ft_lstcount(*lst_b) > 101)
	{
		i = quick_b1a(lst_a, lst_b, med, 0);
		i = quick_b1b(lst_a, lst_b, med, i);
		quick_b1c(lst_a, lst_b, med, i);
	}
	else
		quick_b1(lst_a, lst_b, med, 0);
	select_b3(lst_a, lst_b);
}
