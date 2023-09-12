/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:09:25 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 17:45:58 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_elemements(char *line, size_t len)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < (int)len - 1)
	{
		if (line[i] == 'C' || line[i] == 'E' || line[i] == 'P' || line[i] == '0'
			|| line[i] == '1')
			flag = 1;
		else
		{
			perror("Error\nMap can only have these elements: C, E, P, 0 or 1.\n");
			return (0);
		}
		i++;
	}
	return (flag);
}

int	valid_path(void)
{
	if (clone_m()->n_collect == map()->n_collect && clone_m()->n_exit
		== map()->n_exit && clone_m()->n_players == map()->n_players)
		return (1);
	else
	{
		perror("Error\nNot valid map path.\n");
		return (0);
	}
}

void	check_map_path(char **matris, size_t y, size_t x)
{
	if (y >= map()->n_lines || x >= map()->len_line || matris[y][x] == '1')
		return ;
	if (matris[y][x] == 'C')
		clone_m()->n_collect++;
	if (matris[y][x] == 'E')
		clone_m()->n_exit++;
	if (matris[y][x] == 'P')
		clone_m()->n_players++;
	if (matris[y][x] == 'P' || matris[y][x] == '0'
		|| matris[y][x] == 'E' || matris[y][x] == 'C')
	{
		matris[y][x] = 'X';
		check_map_path(matris, y, x - 1);
		check_map_path(matris, y, x + 1);
		check_map_path(matris, y - 1, x);
		check_map_path(matris, y + 1, x);
	}
}

int	create_map_clone(char **matrix)
{
	size_t	x;
	size_t	y;

	y = 0;
	clone_m()->matris = malloc(sizeof(char *) * (map()->n_lines + 1));
	while (y < map()->n_lines)
	{
		x = 0;
		clone_m()->matris[y] = malloc(sizeof(char) * map()->len_line + 1);
		while (x < map()->len_line - 1)
		{
			if (matrix[y][x] == 'P')
			{
				player()-> y = y; 
				player()-> x = x;
			}
			clone_m()->matris[y][x] = matrix[y][x];
			x++;
		}
		clone_m()->matris[y][x] = 0;
		y++;
	}
	clone_m()->matris[y] = 0;
	check_map_path(clone_m()->matris, player()-> y, player()-> x);
	return (valid_path());
}
