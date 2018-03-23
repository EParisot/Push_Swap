/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/23 00:21:11 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../srcs_common/common.h"

static SDL_Window	*verbose(t_list **lst_a, t_list **lst_b, int *v_fl)
{
	static SDL_Renderer	*renderer;
	static SDL_Window	*window;

	if (ft_lstcount(*lst_a) + ft_lstcount(*lst_b) < 1900)
	{
		if (*v_fl && window == NULL)
		{
			if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
			{
				ft_printf("Error\n");
				return (NULL);
			}
			SDL_CreateWindowAndRenderer(1920, 800, 0, &window, &renderer);
			if (!window || !renderer)
			{
				ft_printf("Error\n");
				SDL_Quit();
				return (NULL);
			}
		}
		w_clear(renderer);
		w_draw(renderer, *lst_a, *lst_b);
		SDL_Delay(LATENCY);
	}
	return (window);
}

static int			io(t_list *lst_a)
{
	while (lst_a->next)
	{
		if ((*(int*)lst_a->next->content) > (*(int*)lst_a->content))
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

static int			check_instru(char *instruct)
{
	int	check;

	check = 0;
	(!ft_strcmp(instruct, "sa")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "sb")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "ss")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "pa")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "pb")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "ra")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "rb")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "rr")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "rra")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "rrb")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "rrr")) ? check = 1 : 0;
	(!ft_strcmp(instruct, "")) ? check = 1 : 0;
	if (check == 1)
		return (1);
	return (0);
}

static int			read_instru(t_list **lst_a, t_list **lst_b, \
		char *instruct, int *v_fl)
{
	if (check_instru(instruct))
	{
		(!ft_strcmp(instruct, "sa")) ? sa(lst_a) : 0;
		(!ft_strcmp(instruct, "sb")) ? sb(lst_b) : 0;
		(!ft_strcmp(instruct, "ss")) ? ss(lst_a, lst_b) : 0;
		(!ft_strcmp(instruct, "pa")) ? pa(*lst_a, *lst_b) : 0;
		(!ft_strcmp(instruct, "pb")) ? pb(*lst_a, *lst_b) : 0;
		(!ft_strcmp(instruct, "ra")) ? ra(lst_a) : 0;
		(!ft_strcmp(instruct, "rb")) ? rb(lst_b) : 0;
		(!ft_strcmp(instruct, "rr")) ? rr(lst_a, lst_b) : 0;
		(!ft_strcmp(instruct, "rra")) ? rra(lst_a) : 0;
		(!ft_strcmp(instruct, "rrb")) ? rrb(lst_b) : 0;
		(!ft_strcmp(instruct, "rrr")) ? rrr(lst_a, lst_b) : 0;
		if (*v_fl && check_instru(instruct) && ft_strcmp(instruct, ""))
			verbose(lst_a, lst_b, v_fl);
	}
	else
		return (0);
	return (1);
}

void				checker(t_list **lst_a, int *v_fl)
{
	t_list			*lst_b;
	char			**line;
	SDL_Window		*window;

	window = NULL;
	if ((line = (char **)malloc(sizeof(char *))) == NULL)
		return ;
	lst_b = ft_lstnew(NULL, sizeof(int));
	(*v_fl) ? window = verbose(lst_a, &lst_b, v_fl) : 0;
	while (get_next_line(0, line))
	{
		if (!read_instru(lst_a, &lst_b, *line, v_fl) || !ft_strcmp(*line, ""))
		{
			if (!read_instru(lst_a, &lst_b, *line, v_fl))
				ft_printf("Error\n");
			break ;
		}
		free(*line);
	}
	if (*line && check_instru(*line))
		(io(*lst_a) && !lst_b->content) ? ft_printf("OK\n") : ft_printf("KO\n");
	ft_lstdel(&lst_b, del);
	w_destroy(window);
	free(*line);
	free(line);
}
