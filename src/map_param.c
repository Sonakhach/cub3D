#include "cub3d.h"



char **get_param(char **str, t_vars *vars)
{
	int i;
	char **nort;

	i = -1;
	while (str[++i] && i < 6)
	{
		nort = ft_split(str[i], ' ');
		if (ft_isdigit(nort[1][0]) == 0)
				check_path(nort[1], ".xpm");
		if (ft_strcmp(nort[0], "NO") == 0)
			vars->no = nort;
		else if (ft_strcmp(nort[0], "SO") == 0)
			vars->so = nort;
		else if (ft_strcmp(nort[0], "EA") == 0)
			vars->ea = nort;
		else if (ft_strcmp(nort[0], "WE") == 0)
			vars->we = nort;
		else if (ft_strcmp(nort[0], "F") == 0)
			vars->floor = nort;
		else if (ft_strcmp(nort[0], "C") == 0)
			vars->ceiling = nort;
		else
			return (NULL);
	}
	return (nort);
}

char *get_map_param(char	**str)
{
	int i;
	char *map01;

	map01 = NULL;
	i = 0;
	while (str[i] && i < 6)
	{
		if (!map01)
			map01 = ft_strdup(str[i]);
		else
			map01 = ft_strjoin(map01, str[i]);
		map01 = ft_strjoin(map01, "\n");
		i++;	
	}
	return (map01);
}

char	**get_matrix_map_param(t_vars *vars)
{
	char	*map_line;

	map_line = get_map_param(vars->matrix);
    vars->map_param = ft_split(map_line, '\n');
	free(map_line);
	return (0);
}


int cmp_param(t_vars *vars)
{
	int i;
	char **str;
	char **row;
	char *ptr;
	
	i = 0;
	ptr = get_map_param(vars->map_param);
	str = ft_split(ptr, '\n');
	while (str[i] && i < 6)
	{
		row = ft_split(str[i], ' ');
		cmp_param_inner(vars, row);
		free(str[i]);
		i++;
	}
	free(ptr);
	free(str);
	return (0);
}

void cmp_param_inner(t_vars *vars, char **row)
{
	int col;

	col = 0;
	while (row[col])
        {
            if (ft_strcmp(row[col], "NO") == 0)
                vars->count_no++;
            else if (ft_strcmp(row[col], "SO") == 0)
                vars->count_so++;
            else if (ft_strcmp(row[col], "EA") == 0)
                vars->count_ea++;
            else if (ft_strcmp(row[col], "WE") == 0)
                vars->count_we++;
            else if (ft_strcmp(row[col], "F") == 0)
                vars->count_f++;
            else if (ft_strcmp(row[col], "C") == 0)
                vars->count_c++;
			free(row[col]);
            col++;
        }
		free(row);	
}
