/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:59:17 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/10 15:20:46 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

#include "../libft/libft.h"
#include "../printf/srcs/ft_printf.h"
#include "../GNL/get_next_line.h"

void	lst_print(t_list *lst);
void	checker(t_list *lst);
void	read_instruct(t_list *lst_a, t_list *lst_b, char *instruct);
void	del(void *content, size_t content_size);

#endif
