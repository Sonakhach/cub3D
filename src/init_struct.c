/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:11:34 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 13:30:47 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	init_param_struct(t_vars *vars, t_cub *cub)
{
	cub->no = vars->no[1];
	cub->so = vars->so[1];
	cub->we = vars->we[1];
	cub->ea = vars->ea[1];
}

void	init_colors_ceiling(t_vars *vars, t_cub *cub)
{
    int     i;
    int     j;
    char    *ptr;
    int     number;

    i = 1;
    j = 0;
    while (vars->ceiling[i])
    {
        ptr = ft_strtrim(vars->ceiling[i], ",");
        number = ft_atoi(ptr);
        cub->f_color[j] = number;
        free(ptr);
        j++;
        i++;
    }
}

void	init_colors_floor(t_vars *vars, t_cub *cub)
{
    int     i;
    int     j;
    char    *ptr;
    int     number;

    i = 1;
    j = 0;

    while (vars->floor[i])
    {
        ptr = ft_strtrim(vars->floor[i], ",");
		number = ft_atoi(ptr);
        cub->f_color[j] = number;
        free(ptr);
        j++;
        i++;
    }
}

void    init_colors(t_vars *vars, t_cub *cub)
{
    init_colors_floor(vars, cub);
    init_colors_ceiling(vars, cub);
}
