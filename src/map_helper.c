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

void	ft_print(char **str)
{	
	int	j;

	j = 0;
	while (str[j])
		j++;
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

void check_digit(char **nort)
{	
	if (!nort[1])
		exit(1);
	else if(ft_isdigit(nort[1][0]) == 0)
		check_path(nort[1], ".xpm");
}

// void free_double(char **x)
// {
// 	int	i;

// 	i = 0;
// 	while (x[i])
// 		free (x[i]);
// 	free(x);
// }