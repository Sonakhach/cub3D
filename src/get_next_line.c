/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:28:12 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/27 16:40:13 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fun(int fd, char **str)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];

	i = 0;
	while (1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (0);
		buf[i] = '\0';
		if (!*str)
			*str = ft_strdup(buf);
		else
			*str = ft_strjoin(*str, buf);
		if (ft_strchr(buf, '\n') || i == 0)
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			i;
	char		*line;
	char		*tmp;

	if (!fun(fd, &str))
		return (0);
	i = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n')) + 1;
	line = ft_substr(str, 0, i);
	tmp = str;
	str = ft_substr(str, i, ft_strlen(str));
	free(tmp);
	return (line);
}
