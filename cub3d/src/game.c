/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjorge-d <fjorge-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:29:05 by fjorge-d          #+#    #+#             */
/*   Updated: 2024/06/26 16:53:14 by fjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//end_game() -> exit_game()?
int	end_game(t_game *game)
{
	exit_game(game, &game->img, 0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		end_game (game);
	else if (keycode == XK_w)
		move_base (D_FRONT, game);
	else if (keycode == XK_s)
		move_base (D_BACK, game);
	else if (keycode == XK_a)
		move_base (D_LEFT, game);
	else if (keycode == XK_d)
		move_base (D_RIGHT, game);
	else if (keycode == XK_Right)
		rotate_view(D_RIGHT, game);
	else if (keycode == XK_Left)
	{
		rotate_view(D_LEFT, game);
	}
	return (0);
}

int	start_game(void)
{
	t_game	game;
	int		flag;

	init_map(&game);
	init_mlx(&game.window);
	if (game.window.mlx == NULL)
		exit_game(&game, &game.img, 1);
	game.window.mlx_win = mlx_new_window(game.window.mlx, game.window.w, \
		game.window.h, "Cub3D");
	flag = init_images(&game);
	if (flag > 0)
	{
		ft_printf("%sError!\nInvalid sprite.\n%s", RED, RESET);
		exit_game(&game, &game.img, flag);
	}
	init_player(&game.map, &game.player);
	raycast(&game);
	mlx_hook (game.window.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook (game.window.mlx_win, 17, 0, end_game, &game);
	mlx_loop(game.window.mlx);
	exit_game(&game, &game.img, 0);
	return (0);
}
