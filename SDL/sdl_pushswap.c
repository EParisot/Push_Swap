#include "sdl_pushswap.h"

SDL_Window	*w_init(SDL_Window *window)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_printf("Error\n");
		SDL_Quit();
		return (NULL);
	}
	window = SDL_CreateWindow("PushSwap", \
			SDL_WINDOWPOS_UNDEFINED, \
			SDL_WINDOWPOS_UNDEFINED, \
			800, 600, \
			SDL_WINDOW_SHOWN);
	if (window == 0)
	{
		ft_printf("Error\n");
		SDL_Quit();
		return (NULL);
	}
	return (window);
}

void	w_draw(SDL_Renderer *renderer, t_list *lst_a, t_list *lst_b, char *inst)
{
	SDL_Rect	r;
	int			i;
	int			count_a;
	int			max_a;
	int			min_a;
	int			count_b;
	int			max_b;
	int			min_b;
	static int	max;
	static int	count;

	i = 0;
	count_a = (int)ft_lstcount(lst_a);
	max_a = ft_lstmax(lst_a);
	min_a = ft_lstmin(lst_a);
	if (max < max_a)
	{
		max = max_a;
		count = count_a;
	}
	count_b = 0;
	(lst_b->content) ? count_b = (int)ft_lstcount(lst_b) : 0;
	(lst_b->content) ? max_b = ft_lstmax(lst_b) : 0;
	(lst_b->content) ? min_b = ft_lstmin(lst_b) : 0;
	r.w = (780 - count) / count;
	w_clear(renderer);
	while (lst_a && lst_a->content)
	{
		r.h = -200 * (*(int*)lst_a->content) / max;
		r.x = 780 - i * r.w + (i + 1 * 10) - r.w;
		r.y = 200;
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &r);
		lst_a = lst_a->next;
		i++;
	}
	i = 0;
	while (lst_b && lst_b->content)
	{
		r.h = -200 * (*(int*)lst_b->content) / max;
		r.x = 780 - i * r.w + (i + 1 * 10) - r.w;
		r.y = 600;
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &r);
		lst_b = lst_b->next;
		i++;
	}
	SDL_RenderPresent(renderer);
}

void	w_clear(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void	w_destroy(SDL_Window *window)
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int		test()
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		events;
	int				end;

	end = 0;
	window = NULL;
	window = w_init(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);






	while (!end)
	{
		SDL_WaitEvent(&events);
		if(events.window.event == SDL_WINDOWEVENT_CLOSE)
			end = 1;
	}

	w_destroy(window);
	return (0);
}
