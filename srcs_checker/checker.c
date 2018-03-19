/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/19 19:25:52 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../srcs_common/common.h"

static void			lst_print(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (lst && (int*)lst->content != NULL)
	{
		ft_printf("%d\n", *((int*)lst->content));
		lst = lst->next;
	}
	lst = tmp;
}

static SDL_Window	*verbose(t_list **lst_a, t_list **lst_b, \
		char *instruct, int *v_fl)
{
	if (DEBUG)
	{
		(!ft_strcmp(instruct, "")) ? instruct = "End" : 0;
		ft_printf("instruction : %s\n", instruct);
		ft_printf("--\n");
		lst_print(*lst_a);
		ft_printf("--\n");
		lst_print(*lst_b);
		ft_printf("--\n");
	}
	static SDL_Window		*window;
	static SDL_Renderer		*renderer;

	if (*v_fl && window == NULL)
	{
		window = w_init(window);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
	w_draw(renderer, *lst_a, *lst_b);
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

static int			read_instru(t_list **lst_a, t_list **lst_b, \
		char *instruct, int *v_fl)
{
	if (ft_strstr("sa-sb-ss-pa-pb-ra-rb-rr-rra-rrb-rrr", instruct))
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
		if (*v_fl)
			verbose(lst_a, lst_b, instruct, v_fl);
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

	if ((line = (char **)malloc(sizeof(char *))) == NULL)
		return ;
	lst_b = ft_lstnew(NULL, sizeof(int));
	(*v_fl) ? window = verbose(lst_a, &lst_b, "", v_fl) : 0;
	while (get_next_line(1, line))
	{
		if (!read_instru(lst_a, &lst_b, *line, v_fl))
		{
			ft_printf("Error\n");
			break ;
		}
		else if (!ft_strcmp(*line, ""))
			break ;
		free(*line);
	}
	if (*line && ft_strstr("sa-sb-ss-pa-pb-ra-rb-rr-rra-rrb-rrr", *line))
		(io(*lst_a) && !lst_b->content) ? ft_printf("OK\n") : ft_printf("KO\n");
	ft_lstdel(&lst_b, del);
	w_destroy(window);
	free(*line);
	free(line);
}
