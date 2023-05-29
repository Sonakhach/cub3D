/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:19:31 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/29 11:38:16 by sokhacha         ###   ########.fr       */
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

char	*no_tab(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}

int	map_check_error(char **str)
{
	int	i;
	int	j;
	int	len;
	int	new_len;

	i = 1;
	while (str[i])
	{
		len = ft_strlen(str[i - 1]);
		new_len = ft_strlen(str[i]);
		j = 0;
		while (str[i][j])
		{
			if ((len < new_len) && str[i][j] == '0' && j > len)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
