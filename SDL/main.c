#include "../../../Library/Frameworks/SDL2.framework/Headers/SDL.h"
#include "../printf/srcs/ft_printf.h"
#include <unistd.h>

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
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (window == 0)
	{
		ft_printf("Error\n");
		SDL_Quit();
		return (NULL);
	}
	return (window);
}

void	w_draw(SDL_Renderer *renderer, int x, int y, int w, int h)
{
	SDL_Rect r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &r);
	SDL_RenderPresent(renderer);
}

void		w_clear(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void	w_destroy(SDL_Window *window)
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int		main()
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		events;
	int				end;

	end = 0;
	window = NULL;
	window = w_init(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	w_draw(renderer, 50, 50, 50, 200);
	sleep(2);
	w_clear(renderer);

	while (!end)
	{
		SDL_WaitEvent(&events);
		if(events.window.event == SDL_WINDOWEVENT_CLOSE)
			end = 1;
	}

	w_destroy(window);
	return (0);
}
