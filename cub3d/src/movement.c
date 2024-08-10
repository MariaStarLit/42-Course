/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjorge-d <fjorge-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:34:18 by fjorge-d          #+#    #+#             */
/*   Updated: 2024/06/27 13:35:21 by fjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_in_map(t_game	*game, double x, double y, t_map *map)
{
	if (!map->map[(int)y] || !map->map[(int)y][(int)x] || \
		map->map[(int)y][(int)x] == '1')
		return (1);
	if (map->map[(int)(y + game->player.speed)][(int)x] == '1' || \
		map->map[(int)y][(int)(x + game->player.speed)] == '1' || \
		map->map[(int)(y - game->player.speed)][(int)x] == '1' || \
		map->map[(int)y][(int)(x - game->player.speed)] == '1')
		return (1);
	return (0);
}

int	move_char(double angle, t_game *game)
{
	double	x;
	double	y;

	x = game->player.x + cos(angle) * game->player.speed;
	y = game->player.y + sin(angle) * game->player.speed;
	if (!check_in_map(game, x + 0.1 * cos(angle), \
		y + 0.1 * sin(angle), &game->map))
	{
		game->player.x = x;
		game->player.y = y;
		raycast(game);
	}
	return (0);
}

int	move_base(t_drct dir, t_game *game)
{
	if (dir == D_FRONT)
		move_char(game->player.angle, game);
	else if (dir == D_BACK)
		move_char(game->player.back, game);
	else if (dir == D_LEFT)
		move_char(game->player.left, game);
	else if (dir == D_RIGHT)
		move_char(game->player.right, game);
	return (0);
}

static int	update_angles(t_game *game)
{
	game->player.back = game->player.angle + PI;
	game->player.right = game->player.angle + PI / 2;
	game->player.left = game->player.angle - PI / 2;
	return (0);
}

int	rotate_view(t_drct dir, t_game *game)
{
	if (dir == D_LEFT)
		game->player.angle -= game->player.view_sens;
	else if (dir == D_RIGHT)
		game->player.angle += game->player.view_sens;
	if (game->player.angle >= 2 * PI)
		game->player.angle -= 2 * PI;
	else if (game->player.angle <= -2 * PI)
		game->player.angle += 2 * PI;
	update_angles(game);
	raycast(game);
	return (0);
}
