/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:04:14 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 17:56:00 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_side_walls(char **matris)
{
	size_t	lenl;
	size_t	nl;

	nl = 0;
	lenl = map()->len_line - 2;
	while (nl < map()->n_lines)
	{
		if (matris[nl][0] != '1' || matris[nl][lenl] != '1')
		{
			perror("Error\nFirst and last column of the map must be a wall.\n");
			return (0);
		}
		nl++;
	}
	if (nl == map()->n_lines)
		return (1);
	return (2);
}

int	check_tb_walls(char **matris)
{
	size_t	lenl;
	size_t	nl;

	lenl = 0;
	nl = map()->n_lines - 1;
	while (lenl < map()->len_line - 1)
	{
		if (matris[0][lenl] != '1' || matris[nl][lenl] != '1')
		{
			perror("Error\nTop and bottom line of the map must be a wall.\n");
			return (0);
		}
		lenl++;
	}
	if (lenl == map()->len_line - 1)
		return (1);
	return (2);
}

int	check_n_items(void)
{
	if (map()->n_exit != 1)
	{
		perror("Error\nMap must have one exit 'E'.\n");
		return (0);
	}
	if (map()->n_players != 1)
	{
		perror("Error\nMap must have one player starting position 'P'.\n");
		return (0);
	}
	if (map()->n_collect < 1)
	{
		perror("Error\nMap must have at least one collectible 'C'.\n");
		return (0);
	}
	return (1);
}

int	register_map_components(char **matris, int flag)
{
	size_t	lenl;
	size_t	nl;

	nl = 1;
	lenl = 0;
	while (nl < map()->n_lines - 1)
	{
		lenl = 0;
		flag = check_elemements(matris[nl], map()->len_line);
		if (flag == 0)
			break ;
		while (lenl < map()->len_line)
		{
			if (matris[nl][lenl] == 'C')
				map()->n_collect++;
			if (matris[nl][lenl] == 'E')
				map()->n_exit++;
			if (matris[nl][lenl] == 'P')
				map()->n_players++;
			lenl++;
		}
		nl++;
	}
	return (flag);
}

int	check_map(char **matris)
{
	if (check_side_walls(matris) == 0)
		return (0);
	if (check_tb_walls(matris) == 0)
		return (0);
	if (register_map_components(matris, 1) == 0) 
		return (0);
	if (check_n_items() == 0)
		return (0);
	if (create_map_clone(matris) == 0)
		return (0);
	return (1);
}
