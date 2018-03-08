/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:42:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/09 00:08:05 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/srcs/ft_printf.h"

void	del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

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

int		main(int ac, const char **av)
{
	t_list *lst;
	t_list *new;
	int		*tmp;

	new = NULL;
	if ((tmp = (int*)malloc(sizeof(int*))) == NULL)
		return (0);
	if (ac > 1)
	{
		*tmp = ft_atoi(av[--ac]);
		lst = ft_lstnew(tmp, sizeof(int));
		while (--ac)
		{
			*tmp = ft_atoi(av[ac]);
			new = ft_lstnew(tmp, sizeof(int));
			ft_lstadd(&lst, new);
		}
		lst_print(lst, new);
	}
	ft_lstdel(&lst, del);
	free(tmp);
	return (0);
}
