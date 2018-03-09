/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:42:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/09 21:55:36 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	lst_print(t_list *lst, t_list *tmp)
{
	tmp = lst;
	while (lst)
	{
		ft_printf("%d\n", *((int*)lst->content));
		lst = lst->next;
	}
	lst = tmp;
}

void	checker(t_list *lst_a)
{
	t_list *tmp;
	char **line;

	///////////
	(void)lst_a;
	///////////
	if ((line = (char **)malloc(sizeof(char *))) == NULL)
		return ;
	if((tmp = (t_list*)malloc(sizeof(t_list*))) == NULL)
		return ;
	while (get_next_line(1, line))
	{
		ft_printf("readen : %s\n", *line);
		free(*line);
	}
	free(tmp);
	free(line);
}
