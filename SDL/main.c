#include "/Library/Frameworks/SDL2.framework/Headers/SDL.h"
#include "../printf/srcs/ft_printf.h"

int		main(int argc, char **argv)
{
	SDL_Window *window;
	SDL_Event events;
	int end;

	window = NULL;
	end = 0;
	if ((window = (SDL_Window*)malloc(sizeof(SDL_Window*))) == NULL)
		return (-1);
	if ((window = (SDL_Window*)malloc(sizeof(SDL_Window*))) == NULL)
		return (-1);
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
			SDL_WINDOW_OPENGL);
	while(!end)
	{
		SDL_WaitEvent(&events);
		if(events.type == SDL_QUIT)
			end = 1;
	}
	SDL_Quit();
	return (0);
}
