/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjorge-d <fjorge-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:02:51 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/26 18:27:14 by fjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_raycast(t_game *game)
{
	game->img.rays.img = mlx_new_image(game->window.mlx, game->window.w, \
		game->window.h);
	game->img.rays.addr = mlx_get_data_addr(game->img.rays.img, \
		&game->img.rays.bpp, &game->img.rays.line_length, \
		&game->img.rays.endian);
}

void	init_mlx(t_window *window)
{
	window->mlx = mlx_init();
	window->w = 1024;
	window->h = 768;
}

void	init_angle(t_object *player, char dir)
{
	if (dir == 'N')
		player->angle = -PI / 2;
	else if (dir == 'W')
		player->angle = PI;
	else if (dir == 'S')
		player->angle = PI / 2;
	else if (dir == 'E')
		player->angle = 0;
	player->back = player->angle + PI;
	player->right = player->angle + PI / 2;
	player->left = player->angle - PI / 2;
	player->view_sens = PI / 60;
}

//printf ("Player = %c\n", map->map[i][j]);
void	init_player(t_map *map, t_object *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || \
				map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				break ;
			}
			j++;
		}
		if (map->map[i][j])
			break ;
		i++;
		j = 0;
	}
	player->speed = 0.1;
	init_angle(player, map->map[i][j]);
}

void	init_map(t_game *game)
{
	game->map.map = map()->matrix;
	game->map.height = map()->n_lines;
	game->map.width = map()->long_line;
	game->map.grid_size = 64;
}
