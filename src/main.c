#include "cub3d.h"

void ft_print(char **str)
{	
	int j;

	j = 0;
	while (str[j])
    {
        printf("str %s\n", str[j]);        
        j++;
    }
}

int  empty_lin(char *str)
{
	int i;
	int count_later;

	i = 0;
	count_later = 0;
	while ( str[i] && str[i] != '\n')
	{
		if (str[i] > 32)
			count_later++;
			
		i++;
	}
	if (count_later != 0)
		return (1);
	return (0);
}

void struct_zero(t_vars *vars)
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
}

void	check_errors(t_vars *vars)
{
	if (get_param(vars->matrix, vars) == NULL || get_storacet_count(vars->floor) || get_storacet_count(vars->ceiling) || param_count(vars)
		|| error_map01(vars->map01) || error_map01_param(vars->map01))
		{
			write (2, "Error count\n", 12);
			exit (1);
		} 
		
	if(get_er_par_count(vars->no) || get_er_par_count(vars->so) || get_er_par_count(vars->ea) || get_er_par_count(vars->we)
		|| map01_check_error(vars->map01, vars) || error_wall(vars->map01) || map01_plyer_count(vars->map01, vars))
		{
			write (2, "Error param count\n", 18);
			exit (1);
		} 
}

int main(int ac, char **av)
{
    (void)ac;
    t_vars	vars;
   
    if (ac == 2)
    {
		struct_zero(&vars);
        check_path(av[1],".cub");
        vars.matrix = get_matrix(av[1], &vars);
		get_matrix_map01(&vars);// 0, 1
		get_matrix_map_param(&vars);// NO, SO, WE, EA ,F, C
		cmp_param(&vars);//error param count
		check_errors(&vars);
	}
	ft_print(vars.matrix);
    return (0);
}