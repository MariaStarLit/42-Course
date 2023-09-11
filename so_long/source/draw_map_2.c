/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:48:54 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 13:10:16 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tree(t_sprites *img, size_t y, size_t x)
{
	mlx_put_image_to_window(\
	map()->mlx, map()->window, img->wall, x * 64, y * 64);
}

void	draw_grass(t_sprites *img, size_t y, size_t x)
{
	mlx_put_image_to_window(\
	map()->mlx, map()->window, img->empty, x * 64, y * 64);
}

void	draw_player(t_sprites *img, size_t y, size_t x)
{
	mlx_put_image_to_window(\
	map()->mlx, map()->window, img->player, x * 64, y * 64);
}

void	draw_eevee(t_sprites *img, size_t y, size_t x)
{
	mlx_put_image_to_window(\
	map()->mlx, map()->window, img->collect, x * 64, y * 64);
}

void	draw_pokeball(t_sprites *img, size_t y, size_t x)
{
	map()->exit_y = y;
	map()->exit_x = x;
	mlx_put_image_to_window(\
	map()->mlx, map()->window, img->exit, x * 64, y * 64);
}
