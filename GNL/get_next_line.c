/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:57:48 by eparisot          #+#    #+#             */
/*   Updated: 2017/12/13 15:05:05 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_realloc(char **line, size_t size)
{
	size_t	len;
	char	new[ft_strlen(*line) + 1];

	len = 0;
	if (*line)
		len = ft_strlen(*line);
	ft_memmove(new, *line, len);
	free(*line);
	if (!(*line = (char *)malloc((len + size) * sizeof(char))))
		return (0);
	ft_memmove(*line, new, len);
	return (1);
}

static int	ft_return(long readen, int i, char **line)
{
	if (readen == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (readen == 0 && i != 0)
	{
		(*line)[i] = '\0';
		return (1);
	}
	free(*line);
	*line = NULL;
	return (0);
}

static int	ft_read_line(char **line, char *rest, int i, int fd)
{
	char		buff[BUFF_SIZE + 1];
	int			j;
	long		readen;

	j = 0;
	readen = 0;
	while ((readen = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		buff[readen] = '\0';
		while (buff[j] && buff[j] != '\n')
			(*line)[i++] = buff[j++];
		if (buff[j] == '\n')
		{
			(*line)[i] = '\0';
			ft_strcpy(rest, buff + j + 1);
			return (1);
		}
		j = 0;
		if (!ft_realloc(line, BUFF_SIZE))
			return (-1);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	return (ft_return(readen, i, line));
}

int			get_next_line(const int fd, char **line)
{
	int				i;
	static char		rest[12288][BUFF_SIZE];

	i = 0;
	if (BUFF_SIZE > 8000000 || !line || !(*line = ft_memalloc(BUFF_SIZE)) \
	|| fd < 0 || fd > 12287)
		return (-1);
	if (*rest[fd])
	{
		while (rest[fd][i] && rest[fd][i] != '\n')
		{
			(*line)[i] = rest[fd][i];
			i++;
		}
		if (rest[fd][i] == '\n')
		{
			ft_memmove(rest[fd], rest[fd] + i + 1, BUFF_SIZE);
			return (1);
		}
		ft_bzero(rest[fd], BUFF_SIZE);
	}
	if (!*rest[fd])
		return (ft_read_line(line, rest[fd], i, fd));
	return (1);
}
