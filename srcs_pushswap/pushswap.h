/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:59:17 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/21 16:38:52 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"
# include "../GNL/get_next_line.h"

void	del(void *content, size_t content_size);
void	pushswap(t_list **lst_a);

#endif
