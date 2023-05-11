#include "cub3d.h"

int error_map01(char **str)
{
    int i;
    int j;
    int countW;
    int countE;

    countW = 0;
    countE = 0;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j] )
        {
            if (str[i][j] == 'W')
                countW++;
            else  if (str[i][j] == 'E')
                countE++;
            j++;
        }
        if (countW > 1 || countE > 1)
            return (1);
        i++;
    }
    return (0);
}

int map01_check_error(char **str, t_vars *vars)
{
    int i;
    int j;
    int len;
    
    i = 0;
    while (str[i])
    {
        
        len = ft_strlen(str[i]);
        j = 0;
        while (str[i][j] )
        {
            if ((i == 0 && str[i][j] == '0') || str[i][0] == '0'
            || (i == (vars->count - 7) && str[i][j] == '0') || str[i][len - 1] != '1')
                return(1);
            if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != ' ' && str[i][j] != '\t' && str[i][j] != 'N'
            && str[i][j] != 'S' && str[i][j] != 'W' && str[i][j] != 'E')
                return (1);
            j++;
        }        
        i++;
    }
    return (0);
}

int error_map01_param(char **str)
{
    int i;
    int j;
    int countN;
    int countS;
   
    countN = 0;
    countS = 0;
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j] )
        {
            if (str[i][j] == 'N')
                countN++;
            else  if (str[i][j] == 'S')
                countS++;
            j++;
        }
        if (countN > 1 || countS > 1)
            return (1);
        i++;
    }
    return (0);
}

int error_wall(char **str)
{
    int i;
    int j;
    
    i = 1;
    while (str[i])
    {
        j = 1;
        while (str[i][j])
        {
            if (str[i][j] == '0' && (str[i - 1][j] == '\t' || str[i - 1][j] == ' ' || str[i - 1][j] == '\0'))
                return(1);
            if (str[i][j] == '0' && (str[i + 1][j] == '\t' || str[i + 1][j] == ' ' || str[i + 1][j] == '\0'))
                return(1);
            if (str[i][j] == '0' && (str[i][j - 1] == '\t' || str[i][j - 1] == ' ' || str[i][j - 1] == '\0'))
                return(1);
            if (str[i][j] == '0' && (str[i][j + 1] == '\t' || str[i][j + 1] == ' ' || str[i][j + 1] == '\0'))
                return(1);
            j++;
        }       
        i++;
    }
    return (0);
}

int map01_plyer_count(char **str, t_vars *vars)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j] )
        {
            if (str[i][j] == 'W')
                vars->count_W++;
            else  if (str[i][j] == 'E')
                vars->count_E++;
            else if (str[i][j] == 'N')
                vars->count_N++;
            else  if (str[i][j] == 'S')
                vars->count_S++;  
            j++;
        }
        i++;
    }
    if ((vars->count_N + vars->count_S + vars->count_E + vars->count_W) != 1)
        return (1);
    return (0);
}