/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pushswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:54:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/20 19:40:10 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_pushswap.h"

SDL_Window		*w_init(SDL_Window *window)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_printf("Error\n");
		SDL_Quit();
		return (NULL);
	}
	window = SDL_CreateWindow("PushSwap", \
			SDL_WINDOWPOS_UNDEFINED, \
			SDL_WINDOWPOS_UNDEFINED, \
			800, 800, \
			SDL_WINDOW_SHOWN);
	if (window == 0)
	{
		ft_printf("Error\n");
		SDL_Quit();
		return (NULL);
	}
	return (window);
}

static int		*info(t_list *lst_a, t_list *lst_b, int *info_tab)
{
	info_tab[0] = (int)ft_lstcount(lst_a);
	info_tab[1] = ft_lstmin(lst_a);
	info_tab[2] = ft_lstmax(lst_a);
	(lst_b->content) ? info_tab[3] = (int)ft_lstcount(lst_b) : 0;
	(lst_b->content) ? info_tab[4] = ft_lstmax(lst_b) : 0;
	(lst_b->content) ? info_tab[5] = ft_lstmin(lst_b) : 0;
	return (info_tab);
}

static void		draw(t_list *lst_a, t_list *lst_b, SDL_Renderer *renderer, \
		int *info_tab)
{
	int			i;
	SDL_Rect	r;

	i = info_tab[6] + 1;
	r.w = (790  / i - 1);
	while (lst_a && lst_a->content && --i)
	{
		r.h = -200 * (*(int*)lst_a->content) / info_tab[7];
		r.x = i * r.w;
		r.y = 200;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &r);
		lst_a = lst_a->next;
	}
	i = info_tab[6] + 1;
	while (lst_b && lst_b->content && --i)
	{
		r.h = -200 * (*(int*)lst_b->content) / info_tab[7];
		r.x = i * r.w;
		r.y = 600;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &r);
		lst_b = lst_b->next;
	}
}

void			w_draw(SDL_Renderer *renderer, t_list *lst_a, t_list *lst_b)
{
	static int	max;
	static int	count;
	int			*info_tab;

	if ((info_tab = (int*)malloc(8 * sizeof(int))) == NULL)
		return ;
	info_tab = info(lst_a, lst_b, info_tab);
	if (max < info_tab[2])
	{
		max = info_tab[2];
		count = info_tab[0];
	}
	info_tab[6] = count;
	info_tab[7] = max;
	w_clear(renderer);
	draw(lst_a, lst_b, renderer, info_tab);
	SDL_RenderPresent(renderer);
	free(info_tab);
}

void			w_clear(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void			w_destroy(SDL_Window *window)
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
