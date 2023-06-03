/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:19:07 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/29 11:36:12 by sokhacha         ###   ########.fr       */
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
	if (vars->f_c_flag == 1 || get_storacet_count(vars->floor)
		|| get_storacet_count(vars->ceiling) || (param_count(vars))
		|| error_map01(vars->map01) || error_map01_param(vars->map01)
		|| map_check_error(vars->map01))
		print_error_exit("Error main\n");
	if (get_er_par_count(vars->no) || get_er_par_count(vars->so)
		|| get_er_par_count(vars->ea) || get_er_par_count(vars->we)
		|| map01_check_error(vars->map01, vars) || error_wall(vars->map01)
		|| map01_plyer_count(vars->map01, vars))
		print_error_exit("Error param count\n");
}

void	get_param(char **str, t_vars *vars)
{
	int		i;
	char	**nort;

	i = -1;
	while (str[++i] && i < 6)
	{
		no_tab(str[i]);
		nort = ft_split(str[i], ' ');
		cmp_param_inner(vars, nort[0]);
		check_digit(nort);
		if (get_param_inner(nort, vars, nort[0]) == NULL)
			vars->f_c_flag = 1;
		free(nort[0]);
	}
	vars->f_c_flag = 0;
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
	return (trim);
}

int	main(int ac, char **av)
{
	t_vars				vars;
	t_addres			addres;
	t_for_get_matrix	tmp;

	if (ac == 2)
	{
		check_path(av[1], ".cub");
		struct_zero(&vars);
		vars.matrix = get_matrix(av[1], &vars, &tmp);
		init_structs(&addres);
		get_matrix_map01(&vars, addres.cub);
		get_matrix_map_param(&vars);
		get_param(vars.matrix, &vars);
		check_errors(&vars);
		init_param_struct(&vars, addres.cub);
		init_colors(&vars, addres.cub);
		initializer(&addres);
		init_win(&addres);
		mlx_hook(addres.game->win, 17, 1L << 0, close_game, &addres);
		mlx_hook(addres.game->win, 2, 1L << 0, key_manager, &addres);
		mlx_loop(addres.game->mlx);
	}
	else
		print_error_exit("error arguments\n");
	return (0);
}
