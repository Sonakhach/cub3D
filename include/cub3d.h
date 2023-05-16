#ifndef CUBE3D_H
# define CUBE3D_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct s_vars
{
	
	char	**matrix;
	int 	count;
	char	**no;
	char	**so;
	char	**ea;
	char	**we;
	char	**floor;
	char	**ceiling;
	char	**map01;
	char	**map_param;
	int 	count_no;
	int 	count_so;
	int 	count_ea;
	int 	count_we;
	int 	count_f;
	int 	count_c;
	int 	count_N;
	int 	count_S;
	int 	count_E;
	int 	count_W;

}	t_vars;

void	check_path(char *path, char *args);
char    *get_string(char *av, t_vars *vars);
char	*get_next_line(int fd);
char	**get_matrix(char	*map_binar, t_vars *vars);
char ** get_param(char	**str,   t_vars *vars);
// void ft_print(t_vars *vars);
void ft_print(char **str);
char *get_map_01(char	**str);
char	**get_matrix_map01(/* char	*av,  */t_vars *vars);
int cmp_param(t_vars *vars);
char *get_map_param(char	**str);
char	**get_matrix_map_param(t_vars *vars);
// int cmp_param_we(t_vars *vars);
// int cmp_param_no(t_vars *vars);
// int cmp_param_so(t_vars *vars);
// int cmp_param_ea(t_vars *vars);
int param_count(t_vars *vars);
int get_error_F_C(char	**str/* , t_vars *vars */);
// char **get_F_C(char	**str, t_vars *vars);
// char **add_spaceF(t_vars *vars);
// char **split_with_space_F(t_vars *vars);
char **get_param_fl_ceil(char	**str, t_vars *vars);
int get_storacet_count(char **str);
int get_er_par_count( char **str);
int error_map01(char **str);
int error_map01_param(char **str);
int error_wall(char **str);
int map01_plyer_count(char **str, t_vars *vars);
int  empty_lin(char *str);
void cmp_param_for_zero(t_vars *vars);
void struct_zero(t_vars *vars);
int map01_check_error(char **str, t_vars *vars);
char * get_string_inner(char *map, int		fd,   t_vars *vars);
void cmp_param_inner(t_vars *vars, char **row);
int	get_matrix_len(char	*av, t_vars *vars);
void check_digit(char **nort);

#endif