#include "cub3d.h"

void	struct_zero(t_vars *vars)
{
	vars->count_no = 0;
	vars->count_so = 0;
	vars->count_ea = 0;
	vars->count_we = 0;
	vars->count_f = 0;
	vars->count_c = 0;

	vars->count_N = 0;
	vars->count_S = 0;
	vars->count_E = 0;
	vars->count_W = 0;

	// addres.cub.map = NULL;
	// addres.cub.texture = NULL;
	vars->no = NULL;
	vars->so = NULL;
	vars->we = NULL;
	vars->ea = NULL;
}

void	check_errors(t_vars *vars)
{
	if (get_param(vars->matrix, vars) == NULL || get_storacet_count(vars->floor)
		|| get_storacet_count(vars->ceiling) ||  param_count(vars) 
		||  error_map01(vars->map01) || error_map01_param(vars->map01))
	{
		write (2, "Error count\n", 12);
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

void print_cub(t_cub *cub)
{
	int i = -1;
	while (cub->map && cub->map[++i])
		printf("map[%d] = \"%s\"\n", i, cub->map[i]);
	printf("no = \"%s\"\n", cub->no);
	printf("so = \"%s\"\n", cub->so);
	printf("we = \"%s\"\n", cub->we);
	printf("ea = \"%s\"\n", cub->ea);
	printf("c red = %d\tgreen = %d\tblue = %d\n", cub->c_color[0], cub->c_color[1], cub->c_color[2]);
	printf("f red = %d\tgreen = %d\tblue = %d\n", cub->f_color[0], cub->f_color[1], cub->f_color[2]);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_addres addres;

	if (ac == 2)
	{
		struct_zero(&vars);
		check_path(av[1],".cub");
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
	// ft_print(vars.matrix);
	// ft_print(cub.map);
	return (0);
}