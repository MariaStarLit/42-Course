/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:59:50 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 14:32:33 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_up(void)
{
	if (map()->matrix[player()->y - 1][player()->x] == 'C')
		collect_items(player()->y - 1, player()->x);
	if (map()->matrix[player()->y - 1][player()->x] == 'E')
		exit_pokeball();
	if (map()->matrix[player()->y - 1][player()->x] == '1')
	{
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.p_up, player()->x * 64, player()->y * 64);
		return (0);
	}
	else
	{
		player()->n_moves++;
		draw_n_moves();
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.empty, player()->x * 64, player()->y * 64);
		player()->y--;
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.p_up, player()->x * 64, player()->y * 64);
		return (1);
	}
}

int	move_down(void)
{
	if (map()->matrix[player()->y + 1][player()->x] == 'C')
		collect_items(player()->y + 1, player()->x);
	if (map()->matrix[player()->y + 1][player()->x] == 'E')
		exit_pokeball();
	if (map()->matrix[player()->y + 1][player()->x] == '1')
	{
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.p_down, player()->x * 64, player()->y * 64);
		return (0);
	}
	else
	{
		player()->n_moves++;
		draw_n_moves();
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.empty, player()->x * 64, player()->y * 64);
		player()->y++;
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.p_down, player()->x * 64, player()->y * 64);
		return (1);
	}
}

int	move_left(void)
{
	if (map()->matrix[player()->y][player()->x - 1] == 'C')
		collect_items(player()->y, player()->x - 1);
	if (map()->matrix[player()->y][player()->x - 1] == 'E')
		exit_pokeball();
	if (map()->matrix[player()->y][player()->x - 1] == '1')
	{
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.p_left, player()->x * 64, player()->y * 64);
		return (0);
	}
	else
	{
		player()->n_moves++;
		draw_n_moves();
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.empty, player()->x * 64, player()->y * 64);
		player()->x--;
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.p_left, player()->x * 64, player()->y * 64);
		return (1);
	}
}

int	move_right(void)
{
	if (map()->matrix[player()->y][player()->x + 1] == 'C')
		collect_items(player()->y, player()->x + 1);
	if (map()->matrix[player()->y][player()->x + 1] == 'E')
		exit_pokeball();
	if (map()->matrix[player()->y][player()->x + 1] == '1')
	{
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.p_right, player()->x * 64, player()->y * 64);
		return (0);
	}
	else
	{
		player()->n_moves++;
		draw_n_moves();
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.empty, player()->x * 64, player()->y * 64);
		player()->x++;
		mlx_put_image_to_window(map()->mlx, map()->window, \
		map()->img.p_right, player()->x * 64, player()->y * 64);
		return (1);
	}
}

int	hook(int key)
{
	int	move;

	move = 0;
	if (key == ESC)
		exit_game();
	if (key == W)
		move = move_up();
	if (key == S)
		move = move_down();
	if (key == A)
		move = move_left();
	if (key == D)
		move = move_right();
	return (move);
}
