/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:48:54 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 18:03:39 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	map()->mlx, map()->window, img->p_down, x * 64, y * 64);
}

void	draw_eevee(t_sprites *img, size_t y, size_t x)
{
	img->eevees_nbr++;
	if (img->eevees_nbr == 1)
		mlx_put_image_to_window(\
		map()->mlx, map()->window, img->c_1, x * 64, y * 64);
	if (img->eevees_nbr == 2)
		mlx_put_image_to_window(\
		map()->mlx, map()->window, img->c_2, x * 64, y * 64);
	if (img->eevees_nbr == 3)
		mlx_put_image_to_window(\
		map()->mlx, map()->window, img->c_3, x * 64, y * 64);
	if (img->eevees_nbr == 4)
		mlx_put_image_to_window(\
		map()->mlx, map()->window, img->c_4, x * 64, y * 64);
	if (img->eevees_nbr == 5)
	{
		mlx_put_image_to_window(\
		map()->mlx, map()->window, img->c_5, x * 64, y * 64);
		img->eevees_nbr = 0;
	}
}

void	draw_pokeball(t_sprites *img, size_t y, size_t x)
{
	map()->exit_y = y;
	map()->exit_x = x;
	mlx_put_image_to_window(\
	map()->mlx, map()->window, img->empty, x * 64, y * 64);
}
