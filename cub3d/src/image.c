/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjorge-d <fjorge-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:35:40 by fjorge-d          #+#    #+#             */
/*   Updated: 2024/06/26 15:37:10 by fjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	add_image(t_img_data *img, t_game *game, char *sprite)
{
	img->img = mlx_xpm_file_to_image (game->window.mlx, sprite,
			&game->img.size, &game->img.size);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr (img->img, &img->bpp,
			&img->line_length, &img->endian);
	return (0);
}

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	init_images(t_game *game)
{
	if (add_image(&game->img.north, game, map()->graphics[0]))
		return (2);
	if (add_image(&game->img.south, game, map()->graphics[1]))
		return (3);
	if (add_image(&game->img.west, game, map()->graphics[2]))
		return (4);
	if (add_image(&game->img.east, game, map()->graphics[3]))
		return (5);
	return (0);
}
