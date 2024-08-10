/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:04:20 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/27 19:08:51 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	extract_lines(char *file_map)
{
	int		fd;
	char	*line;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map()->total_lines++;
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}

static int	extract_map_lines(int fd, char *line, int i)
{
	size_t	len;
	int		j;

	j = 0;
	map()->matrix = malloc(sizeof(char *) * (map()->total_lines - i + 2));
	if (map()->matrix == NULL)
		return (1);
	map()->matrix[j] = ft_strdup(line);
	map()->n_lines++;
	free(line);
	while (i < map()->total_lines)
	{
		j++;
		line = get_next_line(fd);
		map()->matrix[j] = ft_strdup(line);
		len = ft_strlen(line);
		if ((int)len > map()->long_line)
			map()->long_line = len;
		free(line);
		map()->n_lines++;
		i++;
	}
	close(fd);
	return (0);
}

static int	find_map(char *line)
{
	int	i;

	i = 0;
	if (!ft_strcmp(line, "\n"))
		return (0);
	while (line[i] == '1' || line[i] == ' ' || line[i] == '0' || \
		line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

static int	extract(char *file_map, int flag, int i)
{
	char	*line;
	int		fd;

	fd = open(file_map, O_RDONLY);
	while (i < map()->total_lines)
	{
		line = get_next_line(fd);
		if (find_map(line))
			flag = 1;
		else if (find_trash(line))
			break ;
		i++;
		if (flag == 1)
			break ;
		free(line);
	}
	if (flag == 1)
		return (extract_map_lines(fd, line, i));
	close(fd);
	return (1);
}

// printf("Map longest line: %d\n", map()->long_line);
// printf("Map number lines: %d\n", map()->n_lines);
// printf("Map total lines: %d\n", map()->total_lines);
// for (int i = 0; i < 6; i++)
// 	ft_printf("graphics: %s%s%s\n", UBLUE, map()->graphics[i], RESET);
// for (int i = 0; i < map()->n_lines; i++)
// 	ft_printf("%d map: %s", i, map()->matrix[i]);
// ft_printf("\n");
void	read_map(char *file_map)
{
	if (extract_lines(file_map) == -1)
		error_message("Can't open map.");
	if (extract(file_map, 0, 0) == 1)
		error_message("No map found.");
	if (find_walls(file_map, 0, 0) == 1)
		error_message("Setting up graphics.");
	if (check_tab(0) == 1)
		error_message("Please provide 4 textures and 2 colors.");
	map()->floor = set_rgb_color(map()->graphics[4]);
	map()->ceiling = set_rgb_color(map()->graphics[5]);
	if (map()->floor == -1 || map()->ceiling == -1)
		error_message("Setting colors.");
	if (check_map() == 1)
		error_message("Invalid map.");
}
