/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:12:56 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/27 13:56:07 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_wall(char *str, char *info, int tab)
{
	char	*wall;
	int		texture;

	if (str[2] != ' ')
	{
		free(info);
		return (1);
	}
	wall = ft_strtrim(str, info);
	free(info);
	texture = open(wall, O_RDONLY);
	if (texture == -1)
	{
		free(wall);
		return (1);
	}
	else
		map()->graphics[tab] = ft_strdup(wall);
	free(wall);
	close(texture);
	return (0);
}

static int	get_wall(char *texture, int i)
{
	char	*info;
	int		j;

	j = 2;
	while (texture[j] == ' ')
		j++;
	if (texture[j] != 't')
		return (1);
	if (map()->tab_graf[i] == 1)
	{
		map()->tab_graf[i] = 2;
		return (1);
	}
	map()->tab_graf[i] = 1;
	if (i == 0)
		info = ft_strdup("NO \n");
	if (i == 1)
		info = ft_strdup("SO \n");
	if (i == 2)
		info = ft_strdup("WE \n");
	if (i == 3)
		info = ft_strdup("EA \n");
	if (ft_wall(texture, info, i))
		return (1);
	return (0);
}

int	find_walls(char *file_map, int flag, int i)
{
	char	*line;
	size_t	len;
	int		fd;

	fd = open(file_map, O_RDONLY);
	while (flag == 0 && i < (map()->total_lines - map()->n_lines))
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		if (ft_strnstr(line, "NO", len))
			flag = get_wall(line, 0);
		if (ft_strnstr(line, "SO", len))
			flag = get_wall(line, 1);
		if (ft_strnstr(line, "WE", len))
			flag = get_wall(line, 2);
		if (ft_strnstr(line, "EA", len))
			flag = get_wall(line, 3);
		if (ft_strnstr(line, "F", len) || ft_strnstr(line, "C", len))
			flag = find_colors(line, len, flag);
		i++;
		free(line);
	}
	close(fd);
	return (flag);
}
