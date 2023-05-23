/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:19:31 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 12:19:33 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_matrix_len(char	*av, t_vars *vars)
{
	char	*map_line;
	int		i;
	int		len;
	int		count;

	i = 0;
	count = 0;
	map_line = get_string(av, vars);
	len = ft_strlen(map_line);
	while (map_line[i])
	{
		if (map_line[i] == ',')
			count++;
		i++;
	}
	free(map_line);
	return (count + len);
}

int	empty_lin(char *str)
{
	int	i;
	int	count_later;

	i = 0;
	count_later = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] > 32)
			count_later++;
		i++;
	}
	if (count_later != 0)
		return (1);
	return (0);
}

void	check_digit(char **nort)
{	
	if (!nort[1])
		exit(1);
	else if (ft_isdigit(nort[1][0]) == 0)
		check_path(nort[1], ".xpm");
}

void	print_cub(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->map && cub->map[++i])
		printf("map[%d] = \"%s\"\n", i, cub->map[i]);
	printf("no = \"%s\"\n", cub->no);
	printf("so = \"%s\"\n", cub->so);
	printf("we = \"%s\"\n", cub->we);
	printf("ea = \"%s\"\n", cub->ea);
	printf("c red = %d\tgreen = %d\tblue = %d\n", cub->c_color[0],
		cub->c_color[1], cub->c_color[2]);
	printf("f red = %d\tgreen = %d\tblue = %d\n", cub->f_color[0],
		cub->f_color[1], cub->f_color[2]);
}
