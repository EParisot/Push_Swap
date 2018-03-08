/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:42:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/08 22:51:44 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/srcs/ft_printf.h"

void	del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

int main(int ac, const char **av)
{
	t_list *lst;
	t_list *new;
	int		i;
	int		*tmp;

	lst = NULL;
	new = NULL;
	i = 1;
	if ((tmp = (int*)malloc(sizeof(int*))) == NULL)
		return (0);
	if (ac > 1)
	{
		*tmp = ft_atoi(av[i]);
		lst = ft_lstnew(tmp, sizeof(int));
		while (i < ac)
		{
			*tmp = ft_atoi(av[i]);
			new = ft_lstnew(tmp, sizeof(int));
			ft_lstadd(&lst, new);
			ft_printf("%d\n", *((int*)lst->content));
			i++;
		}
	}
	ft_lstdel(&lst, del);
	free(tmp);
	return (0);
}
