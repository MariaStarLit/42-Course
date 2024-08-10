/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:48:43 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/27 19:09:44 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <unistd.h> //close, read, write, exit
# include <stdlib.h> //malloc, free,
# include <stdio.h> // printf, perror
# include <string.h> // strerror
# include <fcntl.h> //open
# include <stdbool.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "cub3d.h"

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define UBLUE "\033[4;34m"

# define PI 3.14159265

typedef enum e_drct
{
	D_FRONT,
	D_BACK,
	D_RIGHT,
	D_LEFT
}	t_drct;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		grid_size;
}	t_map;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		h;
	int		w;
}	t_window;

typedef struct s_object
{
	double	x;
	double	y;
	float	speed;
	double	angle;
	double	back;
	double	left;
	double	right;
	double	view_sens;
}	t_object;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_images
{
	t_img_data	north;
	t_img_data	south;
	t_img_data	east;
	t_img_data	west;
	t_img_data	rays;
	int			size;
}	t_images;

typedef struct s_ray
{
	bool	side_x;
	int		mapx;
	int		mapy;
	int		base;
	int		ceiling;
	double	pos_x;
	double	pos_y;
	double	camera;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	dist_x;
	double	dist_y;
	double	ray_x;
	double	ray_y;
	int		pixel;
}	t_ray;

typedef struct s_game
{
	t_window	window;
	t_object	player;
	t_map		map;
	t_images	img;
}	t_game;

typedef struct s_data
{
	char		**matrix;
	int			total_lines;
	int			n_lines;
	int			long_line;
	int			player;
	int			floor;
	int			ceiling;
	char		*graphics[6];
	int			tab_graf[6];
}	t_data;

//game.c
int		start_game(void);
void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color);

//init.c
void	init_raycast(t_game *game);
void	init_mlx(t_window *window);
void	init_angle(t_object *player, char dir);
void	init_player(t_map *map, t_object *player);
void	init_map(t_game *game);

//image.c
int		init_images(t_game *game);

//movement.c
int		move_base(t_drct dir, t_game *game);
int		rotate_view(t_drct dir, t_game *game);

//raycasting.c
int		raycast(t_game *game);

//exit.c
void	error_message(char *msg);
int		exit_game(t_game *game, t_images *img, int flag);

//utils.c
t_data	*map(void);
t_img	*img(void);
int		check_tab(int i);
int		get_mlx_pixel(t_img_data *img, int x, int y);
int		find_trash(char *line);

//***********PARSING***********
//check_map.c
int		check_map(void);

//walls.c
int		find_walls(char *file_map, int flag, int i);

//colors.c
int		set_rgb_color(char *color);
int		find_colors(char *line, size_t	len, int flag);

//parsing.c
void	read_map(char *map);

#endif