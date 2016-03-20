/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:34:52 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/01/12 13:35:40 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int		get_line_length(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static int		no_newline(char *str, int ret)
{
	int i;

	i = 0;
	if (ret == 0)
		return (0);
	if (ret == -4)
		return (1);
	while (i < ret)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

static	char	*fill_line(char *line, char *leftover)
{
	int i;

	i = 0;
	while (leftover[i] != '\0' && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	ft_memmove(leftover, leftover + get_line_length(line) + 1,\
			ft_strlen(leftover));
	return (line);
}

static char		*read_file(int const fd, char *leftover)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	ret = -4;
	tmp = NULL;
	while (no_newline(buff, ret) == 1 && ret != 0)
	{
		tmp = leftover;
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		if ((leftover = ft_strjoin(leftover, buff)) == NULL)
			return (NULL);
		ft_strdel(&tmp);
	}
	return (leftover);
}

int				get_next_line(int const fd, char **line)
{
	static char	*leftover = NULL;

	if (line == 0)
		return (-1);
	if (leftover == NULL)
		leftover = (char*)ft_memalloc(sizeof(char));
	if ((leftover = read_file(fd, leftover)) == NULL)
		return (-1);
	*line = (char *)ft_memalloc(sizeof(char) * get_line_length(leftover) + 1);
	if (leftover[0] != '\0')
		*line = fill_line(*line, leftover);
	else
	{
		ft_strdel(&leftover);
		return (0);
	}
	return (1);
}
