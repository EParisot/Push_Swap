/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:08:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/10 16:29:39 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H

# define COMMON_H

#include "../libft/libft.h"
#include "../printf/srcs/ft_printf.h"
#include "../GNL/get_next_line.h"

void	sa(t_list *lst_a);
void	sb(t_list *lst_b);
void	ss(t_list *lst_a, t_list *lst_b);

void	pa(t_list *lst_a, t_list *lst_b);
void	pb(t_list *lst_a, t_list *lst_b);

void	ra(t_list *lst_a);
void	rb(t_list *lst_b);
void	rr(t_list *lst_a, t_list *lst_b);

void	rra(t_list *lst_a);
void	rrb(t_list *lst_b);
void	rrr(t_list *lst_a, t_list *lst_b);

#endif
