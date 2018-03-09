/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:42:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/09 20:11:26 by eparisot         ###   ########.fr       */
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

int		check(int ac, const char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (ac <= 1)
		return (0);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && (av[i][j] != '-' && av[i][j] != '+'))
				return (0);
			if ((av[i][j] == '-' || av[i][j] == '+') && j != 0)
				return (0);
			j++;
		}
		if (ft_atoi_int(av[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int		check_doubles(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;
	int		j;

	tmp = lst;
	tmp2 = lst;
	i = 0;
	j = 0;
	while (lst)
	{
		j = 0;
		tmp2 = tmp;
		while (tmp2)
		{
			if ((*(int*)lst->content) == (*(int*)tmp2->content) && i != j)
				return (0);
			j++;
			tmp2 = tmp2->next;
		}
		i++;
		lst = lst->next;
	}
	lst = tmp;
	return (1);
}

int		main(int ac, const char **av)
{
	t_list	*lst;
	t_list	*new;
	int		*tmp;
	int		mem;

	if (check((mem = ac), av))
	{
		if ((tmp = (int*)malloc(sizeof(int*))) == NULL)
			return (0);
		*tmp = ft_atoi(av[--ac]);
		lst = ft_lstnew(tmp, sizeof(int));
		while (--ac)
		{
			*tmp = ft_atoi(av[ac]);
			new = ft_lstnew(tmp, sizeof(int));
			ft_lstadd(&lst, new);
		}
		if (check_doubles(lst) && check(mem, av))
			lst_print(lst, new);
		else
			ft_printf("Error\n");
		ft_lstdel(&lst, del);
		free(tmp);
	}
	return (0);
}
