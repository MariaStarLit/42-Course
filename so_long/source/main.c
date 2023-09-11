/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:56:02 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 13:57:48 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_matrix(char *map_file)
{
	size_t		i;
	int			fd;

	i = 0;
	map()->matrix = malloc(sizeof(char *) * (map()->n_lines + 1));
	if (map()->matrix == NULL)
		exit(1);
	fd = open(map_file, O_RDONLY);
	while (i < map()->n_lines)
	{
		map()->matrix[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	map()->matrix[i] = 0;
	map()->len_line = ft_strlen(map()->matrix[0]);
	if (check_map(map()->matrix) == 1)
		draw_window();
}

void	read_map(char *map_file)
{
	int				fd;
	char			*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCan't open map.\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			map()->n_lines++;
		else
			break ;
		free(line);
	}
	close(fd);
	create_matrix(map_file);
}

int	main(int ac, char **av)
{
	size_t			len;
	char			*format;

	format = ".ber";
	if (ac < 2)
	{
		perror("Error\nPlease provide a map.\n");
		exit(1);
	}
	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		if (!ft_strnstr(av[1], format, len))
			perror("Error\nInvalid map format it needs to be: '.ber'.\n");
		else
			read_map(av[1]);
	}
}
