/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:59:17 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/19 17:28:18 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"
# include "../GNL/get_next_line.h"
# include "../SDL/sdl_pushswap.h"

void	lst_print(t_list *lst);
void	checker(t_list **lst, int *v_fl);
int		read_instru(SDL_Renderer *renderer, t_list **lst_a, t_list **lst_b, \
		char *instru, int *v_fl);
void	del(void *content, size_t content_size);

#endif
