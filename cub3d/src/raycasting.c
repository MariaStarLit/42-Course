/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjorge-d <fjorge-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:35:35 by fjorge-d          #+#    #+#             */
/*   Updated: 2024/06/24 18:02:49 by fjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_line(t_game *game, double next_px, t_ray *rays, int text)
{
	int			i;
	int			colour;
	double		position;
	t_img_data	*img;

	i = rays->base;
	position = 0;
	if (rays->side_x && rays->ray_x < 0)
		img = &game->img.east;
	else if (rays->side_x)
		img = &game->img.west;
	else if (rays->ray_y < 0)
		img = &game->img.south;
	else
		img = &game->img.north;
	while (i <= rays->ceiling)
	{
		colour = get_mlx_pixel(img, text, (int)position);
		if (i >= 0 && i < game->window.h)
			my_mlx_pixel_put(&game->img.rays, rays->pixel, i, colour);
		position += next_px;
		i++;
	}
}

static int	draw_ray(t_game *game, t_ray *rays, double dist)
{
	int		height;
	double	wall_x;
	int		text;
	int		i;

	if (!rays->side_x)
		wall_x = rays->pos_x + dist * rays->ray_x;
	else
		wall_x = rays->pos_y + dist * rays->ray_y;
	wall_x -= (int)wall_x;
	i = 0;
	height = game->window.h / dist;
	rays->base = game->window.h / 2 - height / 2;
	rays->ceiling = game->window.h / 2 + height / 2;
	text = wall_x * game->img.size;
	while (i <= game->window.h)
	{
		if (i < rays->base)
			my_mlx_pixel_put(&game->img.rays, rays->pixel, i, map()->ceiling);
		else if (i > rays->ceiling)
			my_mlx_pixel_put(&game->img.rays, rays->pixel, i, map()->floor);
		i++;
	}
	draw_line (game, (double)game->img.size / height, rays, text);
	return (0);
}

static void	find_limit(t_game *game, t_ray *rays, double dx, double dy)
{
	int	step_x;
	int	step_y;

	step_x = 1;
	step_y = 1;
	if (rays->ray_x < 0)
		step_x = -1;
	if (rays->ray_y < 0)
		step_y = -1;
	while (game->map.map[rays->mapy][rays->mapx] && \
		game->map.map[rays->mapy][rays->mapx] != '1')
	{
		if (rays->dist_x < rays->dist_y)
		{
			rays->dist_x += dx;
			rays->mapx += step_x;
			rays->side_x = true;
		}
		else
		{
			rays->dist_y += dy;
			rays->mapy += step_y;
			rays->side_x = false;
		}
	}
}

static int	cast_ray(t_game *game, t_ray *rays)
{
	double	dx;
	double	dy;

	dx = 0;
	dy = 0;
	if (rays->ray_x != 0)
		dx = fabs(1 / rays->ray_x);
	if (rays->ray_y != 0)
		dy = fabs(1 / rays->ray_y);
	rays->mapx = (int)rays->pos_x;
	rays->mapy = (int)rays->pos_y;
	if (rays->ray_x < 0)
		rays->dist_x = (rays->pos_x - rays->mapx) * dx;
	else
		rays->dist_x = (rays->mapx + 1 - rays->pos_x) * dx;
	if (rays->ray_y < 0)
		rays->dist_y = (rays->pos_y - rays->mapy) * dy;
	else
		rays->dist_y = (rays->mapy + 1 - rays->pos_y) * dy;
	find_limit(game, rays, dx, dy);
	if (!rays->side_x)
		draw_ray (game, rays, rays->dist_y - dy);
	else
		draw_ray (game, rays, rays->dist_x - dx);
	return (0);
}

//too mny lines -> remove 2 lines
int	raycast(t_game *game)
{
	t_ray	rays;

	init_raycast(game);
	rays.pixel = 0;
	rays.dir_x = cos (game->player.angle);
	rays.dir_y = sin (game->player.angle);
	rays.plane_x = -rays.dir_y * tan(PI / 6);
	rays.plane_y = rays.dir_x * tan(PI / 6);
	rays.pos_x = game->player.x;
	rays.pos_y = game->player.y;
	while (rays.pixel < game->window.w)
	{
		rays.camera = 2 * (double)rays.pixel / game->window.w - 1;
		rays.ray_x = rays.dir_x + rays.plane_x * rays.camera;
		rays.ray_y = rays.dir_y + rays.plane_y * rays.camera;
		cast_ray(game, &rays);
		rays.pixel++;
	}
	mlx_clear_window(game->window.mlx, game->window.mlx_win);
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_win, \
		game->img.rays.img, 0, 0);
	mlx_destroy_image(game->window.mlx, game->img.rays.img);
	return (0);
}
