/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:07:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/27 13:07:41 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/srcs/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <time.h>

int		main(int ac, char **av)
{
	int		min;
	int		max;
	int		nb;
	int		*tab;
	int		tmp;
	int		i;
	int		j;
	int		k;
	int		success;

	srand(time(NULL));
	min = 0;
	max = 0;
	nb = 0;
	tab = NULL;
	tmp = 0;
	i = 0;
	j = 0;
	k = 0;
	success = 1;
	if (ac == 4)
	{
		min = ft_atoi(av[1]);
		max = ft_atoi(av[2]);
		nb = ft_atoi(av[3]);
		if (nb < max - min)
		{
			k = nb;
			if ((tab = (int*)malloc(nb * sizeof(int))) == NULL)
				return (0);
			while (k >= 0)
			{
				tmp = rand() % (max - min) + min;
				success = 1;
				i = 0;
				while (i < nb)
				{
					if (tmp == tab[i])
					{
						success = 0;
						break;
					}
					i++;
				}
				if (success == 1)
				{
					tab[k] = tmp;
					k--;
				}
			}
			while(j < nb)
			{
				ft_printf("%d ", tab[j]);
				j++;
			}
		}
		else
			ft_printf("Error : nb should be smaller than max - min - 1\n");
	}
	else
		ft_printf("usage : ./arg_maker <min> <max> <nb>\n");
	free(tab);
	return (0);
}
