/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:59:17 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/31 19:29:48 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"
# include "../GNL/get_next_line.h"

void	del(void *content, size_t content_size);
void	sort(t_list **lst_a, t_list **lst_b);
void	small_sort(t_list **lst_a, t_list **lst_b);
void	very_small_sort(t_list **lst_a);
int		io(t_list *lst);
int		iro(t_list *lst);
int		lastval(t_list *lst);
int		blastval(t_list *lst);
int		isinhalf(t_list *lst, int nb);
int		hmb(t_list *lst, int nb);
void	split1(t_list **lst_a, t_list **lst_b, int med);
void	sort1(t_list **lst_a, t_list **lst_b, int med);
int		split2(t_list **lst_a, t_list **lst_b, int max);
void	merge2(t_list **lst_a, t_list **lst_b, int med);

#endif
