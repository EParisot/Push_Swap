/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:10:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/16 15:02:02 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../srcs_common/common.h"

void	lst_print(t_list *lst)
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

void	checker(t_list **lst_a)
{
	t_list	*lst_b;
	char	**line;

	if ((line = (char **)malloc(sizeof(char *))) == NULL)
		return ;
	lst_b = ft_lstnew(NULL, sizeof(int));
	while (get_next_line(1, line))
	{
		if (!read_instru(lst_a, &lst_b, *line))
		{
			ft_printf("Error\n");
			break ;
		}
		else if (!ft_strcmp(*line, ""))
			break ;
		free(*line);
	}
	ft_lstdel(&lst_b, del);
	free(*line);
	free(line);
}

int		read_instru(t_list **lst_a, t_list **lst_b, char *instruct)
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
///////////
		(!ft_strcmp(instruct, "")) ? instruct = "End" : 0;
		ft_printf("instruction : %s\n", instruct);
		ft_printf("--\n");
		lst_print(*lst_a);
		ft_printf("--\n");
		lst_print(*lst_b);
		ft_printf("--\n");
	}
	else
		return (0);
	return (1);
}
