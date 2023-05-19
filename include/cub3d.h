/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:03:03 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 13:21:30 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUBE3D_H
# define CUBE3D_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 42

# define WIDTH			2040
# define HEIGHT			1000

# define ROTATE_SPEED	0.15
# define MOVE_SPEED		0.2

# define RIGHT			124
# define LEFT			123
# define ESC			53
# define A				0
# define S				1
# define D				2
# define W				13

typedef struct s_vars
{
	char	**matrix;
	int		count;
	char	**no;
	char	**so;
	char	**ea;
	char	**we;
	char	**floor;
	char	**ceiling;
	char	**map01;
	char	**map_param;
	int		count_no;
	int		count_so;
	int		count_ea;
	int		count_we;
	int		count_f;
	int		count_c;
	int		count_n;
	int		count_s;
	int		count_e;
	int		count_w;

}	t_vars;

typedef struct s_cub
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_color[3];
	int		c_color[3];
}			t_cub;

typedef struct s_img
{
	void	*ptr;
	char	*img;
	int		bpp;
	int		width;
	int		height;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_game
{
	int		f_color;
	int		c_color;
	int		index;
	void	*mlx;
	void	*win;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		x;
	int		y;
}				t_game;

typedef struct s_index
{
	int	index_no;
	int	index_so;
	int	index_ea;
	int	index_we;
	int	index_c;
	int	index_f;
}				t_index;

typedef struct s_raycasting
{
	double	perpwalldist;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	double	camerax;
	double	raydiry;
	double	raydirx;
	double	planex;
	double	planey;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		stepx;
	int		stepy;
	int		side;
	int		mapx;
	int		mapy;
	int		hit;
}				t_raycasting;

typedef struct s_addres
{
	t_raycasting	*rcasting;
	t_index			*index;
	t_game			*game;
	t_img			*img;
	t_cub			*cub;
}				t_addres;

// parsing part
void	check_path(char *path, char *args);
char	*get_string(char *av, t_vars *vars);
char	*get_next_line(int fd);
char	**get_matrix(char	*map_binar, t_vars *vars);
char	**get_param(char **str, t_vars *vars);
void	ft_print(char **str);
char	*get_map_01(char	**str);
char	**get_matrix_map01(t_vars *vars, t_cub *cub);//poxel enq
int		cmp_param(t_vars *vars);
char	*get_map_param(char	**str);
char	**get_matrix_map_param(t_vars *vars);
int		param_count(t_vars *vars);
int		get_error_F_C(char	**str);
char	**get_param_fl_ceil(char	**str, t_vars *vars);
int		get_storacet_count(char **str);
int		get_er_par_count( char **str);
int		error_map01(char **str);
int		error_map01_param(char **str);
int		error_wall(char **str);
int		map01_plyer_count(char **str, t_vars *vars);
int		empty_lin(char *str);
void	cmp_param_for_zero(t_vars *vars);
void	struct_zero(t_vars *vars);
int		map01_check_error(char **str, t_vars *vars);
char	*get_string_inner(char *map, int fd, t_vars *vars);
void	cmp_param_inner(t_vars *vars, char **row);
int		get_matrix_len(char	*av, t_vars *vars);
void	check_digit(char **nort);
void	init_param_struct(t_vars *vars, t_cub *cub);
void	init_colors(t_vars *vars, t_cub *cub);
void	init_colors_floor(t_vars *vars, t_cub *cub);
void	init_colors_ceiling(t_vars *vars, t_cub *cub);
// void free_all(char **x);

// rayCasting part*** draw_window.c, init_win.c, init_win2.c, init_win3.c, init_win4.c, key_manager.c, structs_implement.c, print_error.c, moves.c
void	init_struct_game(t_addres *address);
void	init_struct_index(t_addres *address);
void	init_struct_img(t_addres *address);
void	init_struct_cub(t_addres *address);
void	init_struct_raycasting(t_addres *address);
void	init_structs(t_addres *address);
void	initializer(t_addres *address);
void	init_win(t_addres *address);
void	continue_init_win(t_addres *address);
void	norm_init_win(t_addres *address);
void	norm_init_win_2(t_addres *address);
void	find_pos_player(t_addres *address);
void	draw_floor_and_celling(t_addres *data, char *dest);
int		ft_texx(t_addres *address, int n);
int		draw_walls(t_addres *address, char *dest, char *dest_2, int texx);
void	norm_init_win_3(t_addres *address);
float	ft_abs(float num);
char	*get_correct_arg(char *ptr);
void	init_plane(t_addres *address, double i, double j);
void	init_dir(t_addres *address, double i, double j);
void	init_player_pos(t_addres *address, int i, int j);
void	ft_get_data_addr(t_addres *address);
int		check_nwse(t_addres *address);
int		key_manager(int key, t_addres *address);
void	print_close(t_addres *address, char *str);
int		close_game(t_addres *address);
void	print_error(t_addres *address, char *err, int flag);
void	rotate_right(t_addres *address, double rotate);
void	move_left(t_addres *address);
void	move_right(t_addres *address);
void	move_up(t_addres *address);
void	move_down(t_addres *address);
void	free_game(t_game *game);
void	free_all(t_addres *address);

#endif