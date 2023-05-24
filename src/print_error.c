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
	free_all(address);
}

int	close_game(t_addres *address)
{
	print_close(address, "Game closed\n");
	exit(0);
}

void	free_all(t_addres *address)
{
	int	i;

	i = -1;
	free(address->rcasting);
	free(address->index);
	free(address->game);
	free(address->img);
	address->rcasting = NULL;
	address->index = NULL;
	address->game = NULL;
	address->img = NULL;
}
