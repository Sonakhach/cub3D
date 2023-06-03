/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:19:44 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/29 11:36:37 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_map_param(char	**str)
{
	int		i;
	char	*map01;

	map01 = NULL;
	i = 0;
	while (str[i] && i < 6)
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

char	**get_matrix_map_param(t_vars *vars)
{
	char	*map_line;
	int		count;

	map_line = get_map_param(vars->matrix);
	vars->map_param = ft_split(map_line, '\n');
	count = 0;
	while (vars->map_param && vars->map_param[count])
		count++;
	free(map_line);
	return (0);
}

void	cmp_param_inner(t_vars *vars, char *row)
{
	if (ft_strcmp(row, "NO") == 0)
		vars->count_no++;
	else if (ft_strcmp(row, "SO") == 0)
		vars->count_so++;
	else if (ft_strcmp(row, "EA") == 0)
		vars->count_ea++;
	else if (ft_strcmp(row, "WE") == 0)
		vars->count_we++;
	else if (ft_strcmp(row, "F") == 0)
		vars->count_f++;
	else if (ft_strcmp(row, "C") == 0)
		vars->count_c++;
}
