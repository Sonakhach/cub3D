/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:20:00 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 12:20:03 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_string_inner(char *map, int fd, t_vars *vars)
{
	char	*map_binar;

	map_binar = NULL;
	while (map)
	{
		if (map[0] == '\0')
			break ;
		if (empty_lin(map))
		{
			if (!map_binar)
				map_binar = ft_strdup(map);
			else
				map_binar = ft_strjoin(map_binar, map);
			vars->count++;
		}
		if ((map[0] == '\n' || !empty_lin(map)) && vars->count > 6)
		{
			write (1, "You have error", 14);
			exit (1);
		}
		free(map);
		map = get_next_line(fd);
	}
	free(map);
	return (map_binar);
}

char	*get_string(char *av, t_vars *vars)
{
	int		fd;
	char	*map;
	char	*line;

	vars->count = 0;
	line = NULL;
	map = NULL;
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Something went wrong\n", 21);
		exit(1);
	}
	map = get_next_line(fd);
	line = get_string_inner(map, fd, vars);
	return (line);
}

char	**get_matrix(char	*av, t_vars *vars)
{
	char	**map_matrix;
	char	*map_line;
	char	*map_line_add_spac;
	int		i;
	int		j;

	i = -1;
	j = 0;
	map_line_add_spac = ft_calloc(get_matrix_len(av, vars) + 1, 1);
	map_line = get_string(av, vars);
	while (map_line[++i])
	{
		if (map_line[i] == ',')
		{
			map_line_add_spac[j++] = map_line[i];
			map_line_add_spac[j] = ' ';
		}
		else
			map_line_add_spac[j] = map_line[i];
		j++;
	}
	map_matrix = ft_split(map_line_add_spac, '\n');
	free(map_line);
	free(map_line_add_spac);
	return (map_matrix);
}

char	*get_map_01(char	**str)
{
	int		i;
	char	*map01;

	map01 = NULL;
	i = 6;
	while (str[i] && i >= 6)
	{
		if (!map01)
			map01 = ft_strdup(str[i]);
		else
			map01 = ft_strjoin(map01, str[i]);
		map01 = ft_strjoin(map01, "\n");
		i++;
	}
	return (map01);
}

char	**get_matrix_map01(t_vars *vars, t_cub *cub)
{
	char	*map_line;

	map_line = get_map_01(vars->matrix);
	vars->map01 = ft_split(map_line, '\n');
	cub->map = vars->map01;
	free(map_line);
	return (0);
}
