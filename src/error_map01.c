/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:24:46 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 13:08:21 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_map01(char **str)
{
	int	i;
	int	j;
	int	count_w;
	int	count_e;

	count_e = 0;
	count_w = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'W')
				count_w++;
			else if (str[i][j] == 'E')
				count_e++;
			j++;
		}
		if (count_w > 1 || count_e > 1)
			return (1);
			i++;
	}
	return (0);
}

int	map01_check_error(char **str, t_vars *vars)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		j = 0;
		while (str[i][j])
		{
			if ((i == 0 && str[i][j] == '0') || str[i][0] == '0'
				|| (i == (vars->count - 7) && str[i][j] == '0')
				|| str[i][len - 1] != '1')
				return (1);
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != ' '
				&& str[i][j] != '\t' && str[i][j] != 'N' && str[i][j] != 'S'
				&& str[i][j] != 'W' && str[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_map01_param(char **str)
{
	int	i;
	int	j;
	int	count_n;
	int	count_s;

	count_n = 0;
	count_s = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N')
				count_n++;
			else if (str[i][j] == 'S')
				count_s++;
			j++;
		}
		if (count_n > 1 || count_s > 1)
			return (1);
		i++;
	}
	return (0);
}

int	error_wall(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i])
	{
		j = 1;
		while (str[i][j])
		{
			if (str[i][j] == '0' && (str[i - 1][j] == '\t'
				|| str[i - 1][j] == ' ' || str[i - 1][j] == '\0'))
				return (1);
			if (str[i][j] == '0' && (str[i + 1][j] == '\t'
				|| str[i + 1][j] == ' ' || str[i + 1][j] == '\0'))
				return (1);
			if (str[i][j] == '0' && (str[i][j - 1] == '\t'
				|| str[i][j - 1] == ' ' || str[i][j - 1] == '\0'))
				return (1);
			if (str[i][j] == '0' && (str[i][j + 1] == '\t'
				|| str[i][j + 1] == ' ' || str[i][j + 1] == '\0'))
				return (1);
			j++;
		}
	}
	return (0);
}

int	map01_plyer_count(char **str, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'W')
				vars->count_w++;
			else if (str[i][j] == 'E')
				vars->count_e++;
			else if (str[i][j] == 'N')
				vars->count_n++;
			else if (str[i][j] == 'S')
				vars->count_s++;
			j++;
		}
		i++;
	}
	if ((vars->count_n + vars->count_s + vars->count_e + vars->count_w) != 1)
		return (1);
	return (0);
}
