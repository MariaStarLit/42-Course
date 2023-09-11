/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:08:37 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 13:52:09 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_items(size_t y, size_t x)
{
	if (player()->n_collect <= map()->n_collect)
		player()->n_collect++;
	if (player()->n_collect == map()->n_collect)
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.exit, map()->exit_x * 64, map()->exit_y * 64);
	map()->matrix[y][x] = '0';
}

void	exit_pokeball(void)
{
	if (player()->n_collect == map()->n_collect)
		exit_game();
}

void	free_map(char **matriz)
{
	size_t	i;

	i = 0;
	while (matriz[i] && matriz)
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

int	exit_game(void)
{
	mlx_destroy_window(map()->mlx, map()->window);
	mlx_destroy_image(map()->mlx, map()->img.player);
	mlx_destroy_image(map()->mlx, map()->img.exit);
	mlx_destroy_image(map()->mlx, map()->img.empty);
	mlx_destroy_image(map()->mlx, map()->img.wall);
	mlx_destroy_image(map()->mlx, map()->img.collect);
	mlx_destroy_display(map()->mlx);
	free_map(clone_m()->matris);
	free_map(map()->matrix);
	free(map()->mlx);
	exit(1);
	return (1);
}
