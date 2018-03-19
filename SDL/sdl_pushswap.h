/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pushswap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:02:34 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/19 15:27:03 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_PUSHSWAP_H

# define SDL_PUSHSWAP_H

# include "../../../Library/Frameworks/SDL2.framework/Headers/SDL.h"
# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"

SDL_Window	*w_init(SDL_Window *window);
void		w_draw(SDL_Renderer *renderer, t_list *lst_a, t_list *lst_b, \
		char *instru);
void		w_clear(SDL_Renderer *renderer);
void		w_destroy(SDL_Window *window);

#endif
