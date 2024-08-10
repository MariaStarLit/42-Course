/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjorge-d <fjorge-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:14:31 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/26 15:40:59 by fjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	free_wall(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < 6)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
}

static void	free_arr(char **arr, int max)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < max)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

void	error_message(char *msg)
{
	ft_printf("%sError!\n%s\n%s", RED, msg, RESET);
	free_wall(map()->graphics);
	free_arr(map()->matrix, map()->n_lines);
	exit(1);
}

int	exit_game(t_game *game, t_images *img, int flag)
{
	if (flag != 1)
	{
		mlx_destroy_window(game->window.mlx, game->window.mlx_win);
		if (flag > 2 || flag == 0)
			mlx_destroy_image(game->window.mlx, img->north.img);
		if (flag > 3 || flag == 0)
			mlx_destroy_image(game->window.mlx, img->south.img);
		if (flag > 4 || flag == 0)
			mlx_destroy_image(game->window.mlx, img->west.img);
		if (flag == 0)
			mlx_destroy_image(game->window.mlx, img->east.img);
		mlx_destroy_display(game->window.mlx);
	}
	free(game->window.mlx);
	free_wall(map()->graphics);
	free_arr(map()->matrix, map()->n_lines);
	exit(0);
	return (0);
}
