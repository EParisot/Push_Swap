#include "../../../Library/Frameworks/SDL2.framework/Headers/SDL.h"
#include "../printf/srcs/ft_printf.h"

int		main()
{
	SDL_Window *window;
	SDL_Event events;
	int end;

	end = 0;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_printf("Error\n");
		SDL_Quit();
		return (-1);
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
		return (-1);
	}
	while(!end)
	{
		SDL_WaitEvent(&events);
		if(events.window.event == SDL_WINDOWEVENT_CLOSE)
			end = 1;
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
