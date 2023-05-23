/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:25:10 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 13:21:50 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_path(char *path, char *args)
{
	int	i;
	int	len;

	len = strlen(path);
	i = 0;
	while (i < len - 4)
		i++;
	path += i;
	if (ft_strcmp(path, args))
	{
		write(1, "ERROR extantion\n", 16);
		exit(1);
	}
}

int	param_count(t_vars *vars)
{
	if (get_error_f_c(vars->floor) || get_error_f_c(vars->ceiling))
		return (1);
	if (vars->count_no != 1 && vars->count_so != 1 && vars->count_ea != 1
		&& vars->count_we != 1 && vars->count_f != 1 && vars->count_c != 1)
		return (1);
	return (0);
}

int	get_error_f_c(char	**str)
{
	int		i;
	int		number;
	int		j;
	char	*ptr;

	i = 1;
	while (str[i])
	{
		j = 0;
		ptr = ft_strtrim(str[i], ",");
		number = ft_atoi(ptr);
		if (ft_strcmp(str[i], ",") == 0)
			return (1);
		if (number < 0 || number > 255)
			return (1);
		while (ptr[j])
		{
			if (ft_isdigit(ptr[j]) == 0)
				return (1);
			j++;
		}
		free(ptr);
		i++;
	}
	return (0);
}

int	get_storacet_count(char **str)
{
	int	i;
	int	count;
	int	len;

	count = 0;
	i = 1;
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (str[i][len - 1] == ',')
			count++;
		if (i == 4)
			return (1);
		i++;
	}
	if (count != 2)
		return (1);
	if (count == 2 && str[3][len - 1] == ',')
		return (1);
	return (0);
}

int	get_er_par_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 2)
			return (1);
		i++;
	}	
	return (0);
}
