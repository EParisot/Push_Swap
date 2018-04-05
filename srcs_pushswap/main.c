/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:42:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/05 13:38:06 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check(int ac, const char **av, int *v_fl)
{
	int		i;
	int		j;

	j = 0;
	if (ac <= 1)
		return (0);
	(!ft_strcmp(av[1], "-v")) ? (*v_fl = 1) : 0;
	(ft_strcmp(av[1], "-v")) ? (*v_fl = 0) : 0;
	i = 1 + *v_fl;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
				return (0);
			if ((av[i][j] == '-' || av[i][j] == '+') && j != 0)
				return (0);
			j++;
		}
		if (ft_is_int(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	check_doubles(t_list *lst)
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

static void	pushswap(t_list **lst_a)
{
	t_list *lst_b;

	lst_b = ft_lstnew(NULL, sizeof(int));
	if (ft_lstcount(*lst_a) <= 3)
		very_small_sort(lst_a);
	else if (ft_lstcount(*lst_a) <= 5)
		small_sort(lst_a, &lst_b);
	else
		sort(lst_a, &lst_b);
	ft_printf("\n");
	ft_lstdel(&lst_b, del);
}

int			main(int ac, const char **av)
{
	t_list	*lst;
	int		*tmp;
	int		*v_fl;

	if ((v_fl = (int*)malloc(sizeof(int *))) == NULL || !check(ac, av, v_fl) \
			|| (tmp = (int*)malloc(sizeof(int *))) == NULL)
		ft_printf("Error\n");
	else
	{
		*tmp = ft_atoi(av[--ac]);
		lst = ft_lstnew(tmp, sizeof(int));
		while (--ac > *v_fl)
		{
			*tmp = ft_atoi(av[ac]);
			ft_lstaddend(&lst, ft_lstnew(tmp, sizeof(int)));
		}
		if (!check_doubles(lst))
			ft_printf("Error\n");
		else
			pushswap(&lst);
		ft_lstdel(&lst, del);
		free(tmp);
		free(v_fl);
	}
	return (0);
}
