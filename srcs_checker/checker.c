/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:42:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/10 15:48:12 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	checker(t_list *lst_a)
{
	t_list *lst_b;
	int *tmp;
	char **line;

	if ((tmp = (int *)malloc(sizeof(int *))) == NULL)
		return ;
	tmp = NULL;
	if ((line = (char **)malloc(sizeof(char *))) == NULL)
		return ;
	lst_b = ft_lstnew(tmp, sizeof(int));
	while (get_next_line(1, line))
	{
		//////////
		//ft_printf("readen : %s\n", *line);
		/////////
		read_instruct(lst_a, lst_b, *line);
		ft_printf("--\n");
		lst_print(lst_a);
		ft_printf("--\n");
		lst_print(lst_b);
		ft_printf("--\n");
		free(*line);
	}
	ft_lstdel(&lst_b, del);
	free(line);
	free(tmp);
}

void	read_instruct(t_list *lst_a, t_list *lst_b, char *instruct)
{
	(void)lst_a;
	(void)lst_b;
	(void)instruct;
	return ;
}
