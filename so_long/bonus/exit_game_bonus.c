/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:08:37 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 14:32:43 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect_items(size_t y, size_t x)
{
	if (player()->n_collect <= map()->n_collect)
		player()->n_collect++;
	if (player()->n_collect == map()->n_collect)
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.exit, clone_m()->exit_x * 64, clone_m()->exit_y * 64);
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
	while (matriz && matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

int	exit_game(void)
{
	mlx_destroy_window(map()->mlx, map()->window);
	mlx_destroy_image(map()->mlx, map()->img.p_up);
	mlx_destroy_image(map()->mlx, map()->img.p_down);
	mlx_destroy_image(map()->mlx, map()->img.p_right);
	mlx_destroy_image(map()->mlx, map()->img.p_left);
	mlx_destroy_image(map()->mlx, map()->img.exit);
	mlx_destroy_image(map()->mlx, map()->img.empty);
	mlx_destroy_image(map()->mlx, map()->img.wall);
	mlx_destroy_image(map()->mlx, map()->img.c_1);
	mlx_destroy_image(map()->mlx, map()->img.c_2);
	mlx_destroy_image(map()->mlx, map()->img.c_3);
	mlx_destroy_image(map()->mlx, map()->img.c_4);
	mlx_destroy_image(map()->mlx, map()->img.c_5);
	mlx_destroy_display(map()->mlx);
	free_map(clone_m()->matris);
	free_map(map()->matrix);
	free(map()->mlx);
	exit(1);
	return (1);
}
