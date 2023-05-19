/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:20:21 by sokhacha          #+#    #+#             */
/*   Updated: 2023/05/19 12:48:16 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_close(t_addres *address, char *str)
{
	write(1, str, ft_strlen(str));
	(void)address;
	free_all(address);
}

int	close_game(t_addres *address)
{
	print_close(address, "Game closed\n");
	exit(0);
}

void	print_error(t_addres *address, char *err, int flag)
{
	write(2, "Error!\n", 7);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	if (flag == 1)
		free_all(address);
	(void)flag;
	(void)address;
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	free(game->mlx);
	free(game->win);
	free(game->no);
	free(game->so);
	free(game->ea);
	free(game->we);
	game->mlx = NULL;
	game->win = NULL;
	game->no = NULL;
	game->so = NULL;
	game->ea = NULL;
	game->we = NULL;
}

void	free_all(t_addres *address)
{
	int	i;

	i = -1;
	// free_cub(address->cub);
	// free_elements(address->elements);
	// free_mtx(address->data.map);
	free_game(address->game);
	while (++i < 5)
	{
		free(address->img[i].img);
		free(address->img[i].ptr);
	}
	free(address->rcasting);
	free(address->index);
	free(address->game);
	free(address->img);
	address->rcasting = NULL;
	address->index = NULL;
	address->game = NULL;
	address->img = NULL;
}
