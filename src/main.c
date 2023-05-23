/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:19:07 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 13:13:28 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_zero(t_vars *vars)
{
	vars->count_no = 0;
	vars->count_so = 0;
	vars->count_ea = 0;
	vars->count_we = 0;
	vars->count_f = 0;
	vars->count_c = 0;
	vars->count_n = 0;
	vars->count_s = 0;
	vars->count_e = 0;
	vars->count_w = 0;
	vars->no = NULL;
	vars->so = NULL;
	vars->we = NULL;
	vars->ea = NULL;
}

void	check_errors(t_vars *vars)
{
	if (get_param(vars->matrix, vars) == NULL || get_storacet_count(vars->floor)
		|| get_storacet_count(vars->ceiling) || param_count(vars)
		|| error_map01(vars->map01) || error_map01_param(vars->map01))
	{
		write (2, "Error main\n", 12);
		exit (1);
	}
	if (get_er_par_count(vars->no) || get_er_par_count(vars->so)
		|| get_er_par_count(vars->ea) || get_er_par_count(vars->we)
		|| map01_check_error(vars->map01, vars) || error_wall(vars->map01)
		|| map01_plyer_count(vars->map01, vars))
	{
		write (2, "Error param count\n", 18);
		exit (1);
	}
}

char	**get_param(char **str, t_vars *vars)
{
	int		i;
	char	**nort;
	char	*trim;

	i = -1;
	while (str[++i] && i < 6)
	{
		nort = ft_split(str[i], ' ');
		trim = ft_strtrim(nort[0], "\t");
		check_digit(nort);
		get_param_inner(nort, vars, trim);
		free(trim);
	}
	return (nort);
}

char	*get_param_inner(char **nort, t_vars *vars, char *trim)
{
	if (ft_strcmp(trim, "NO") == 0)
		vars->no = nort;
	else if (ft_strcmp(trim, "SO") == 0)
		vars->so = nort;
	else if (ft_strcmp(trim, "EA") == 0)
		vars->ea = nort;
	else if (ft_strcmp(trim, "WE") == 0)
		vars->we = nort;
	else if (ft_strcmp(trim, "F") == 0)
		vars->floor = nort;
	else if (ft_strcmp(trim, "C") == 0)
		vars->ceiling = nort;
	else
		return (NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars		vars;
	t_addres	addres;

	if (ac == 2)
	{
		struct_zero(&vars);
		check_path(av[1], ".cub");
		vars.matrix = get_matrix(av[1], &vars);
		init_structs(&addres);
		get_matrix_map01(&vars, addres.cub);
		get_matrix_map_param(&vars);
		cmp_param(&vars);
		check_errors(&vars);
		init_param_struct(&vars, addres.cub);
		init_colors(&vars, addres.cub);
		initializer(&addres);
		init_win(&addres);
		mlx_hook(addres.game->win, 17, 1L << 0, close_game, &addres);
		mlx_hook(addres.game->win, 2, 1L << 0, key_manager, &addres);
		mlx_loop(addres.game->mlx);
	}
	return (0);
}
