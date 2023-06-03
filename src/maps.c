/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:20:00 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/29 11:37:24 by sokhacha         ###   ########.fr       */
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
			print_error_exit("You have error\n");
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
	int		len;

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
	len = ft_strlen(map);
	if (len == 0)
		print_error_exit("Something went wrong\n");
	line = get_string_inner(map, fd, vars);
	return (line);
}

char	**get_matrix(char	*av, t_vars *vars, t_for_get_matrix *tmp)
{
	tmp->i = -1;
	tmp->j = 0;
	tmp->map_line_add_spac = ft_calloc(get_matrix_len(av, vars) + 1, 1);
	tmp->map_line = get_string(av, vars);
	while (tmp->map_line[++tmp->i])
	{
		if (tmp->map_line[tmp->i] == ',')
		{
			tmp->map_line_add_spac[tmp->j++] = tmp->map_line[tmp->i];
			tmp->map_line_add_spac[tmp->j] = ' ';
		}
		else
			tmp->map_line_add_spac[tmp->j] = tmp->map_line[tmp->i];
		tmp->j++;
	}
	tmp->map_matrix = ft_split(tmp->map_line_add_spac, '\n');
	tmp->j = 0;
	while (tmp->map_matrix[tmp->j])
		tmp->j++;
	if (tmp->j < 6)
		print_error_exit("Map is not valid");
	free(tmp->map_line);
	free(tmp->map_line_add_spac);
	return (tmp->map_matrix);
}

char	*get_map_01(char	**str)
{
	int		i;
	char	*map01;

	map01 = NULL;
	i = 6;
	while ((str && str[i]) && i >= 6)
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
	if (map_line == NULL)
	{
		write(2, "Error! No valid map.\n", 21);
		exit(1);
	}
	vars->map01 = ft_split(map_line, '\n');
	cub->map = vars->map01;
	free(map_line);
	return (0);
}
