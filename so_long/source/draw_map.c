/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:46:52 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 16:30:20 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_sprites *img)
{
	img->h = 64;
	img->w = 64;
	img->wall = mlx_xpm_file_to_image(map()->mlx, WALL, &img->w, &img->h);
	img->empty = mlx_xpm_file_to_image(\
	map()->mlx, EMPTY_SPACE, &img->w, &img->h);
	img->player = mlx_xpm_file_to_image(map()->mlx, PLAYER, &img->w, &img->h);
	img->collect = mlx_xpm_file_to_image(\
	map()->mlx, COLLECT, &img->w, &img->h);
	img->exit = mlx_xpm_file_to_image(map()->mlx, EXIT, &img->w, &img->h);
}

void	draw_map(void)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map()->n_lines)
	{
		x = 0;
		while (x < map()->len_line - 1)
		{
			if (map()->matrix[y][x] == '1')
				draw_tree(&map()->img, y, x);
			if (map()->matrix[y][x] == '0')
				draw_grass(&map()->img, y, x);
			if (map()->matrix[y][x] == 'P')
				draw_player(&map()->img, y, x);
			if (map()->matrix[y][x] == 'C')
				draw_eevee(&map()->img, y, x);
			if (map()->matrix[y][x] == 'E')
				draw_pokeball(&map()->img, y, x);
			x++;
		}
		y++;
	}
}

void	draw_window(void)
{
	int					wth;
	int					hgt;
	void				*win;

	wth = ((map()->len_line) - 1) * 64;
	hgt = ((map()->n_lines)) * 64;
	map()->mlx = mlx_init();
	win = mlx_new_window(map()->mlx, wth, hgt, "Pokemon Eevee!");
	map()->window = win;
	create_images(&map()->img);
	draw_map();
	write(1, "Moves: 0\n", 9);
	mlx_key_hook(map()->window, hook, NULL);
	mlx_hook(map()->window, 17, 0, exit_game, NULL);
	mlx_loop(map()->mlx);
}

void	draw_n_moves(void)
{
	char	*moves;
	int		i;

	i = 0;
	moves = ft_itoa(player()->n_moves);
	write(1, "Moves: ", 7);
	while (moves[i])
	{
		write(1, &moves[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(moves);
}
