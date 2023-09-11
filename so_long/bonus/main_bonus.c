/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:56:02 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/11 14:32:29 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	create_matrix(char *map_path, int flag)
{
	size_t		i;
	int			fd;

	i = 0;
	fd = open(map_path, O_RDONLY);
	map()->matrix = malloc(sizeof(char *) * (map()->n_lines + 1));
	if (map()->matrix == NULL)
		exit(1);
	while (i < map()->n_lines)
	{
		map()->matrix[i] = get_next_line(fd);
		i++;
	}
	map()->matrix[i] = 0;
	map()->len_line = ft_strlen(map()->matrix[0]);
	close(fd);
	flag = check_map(map()->matrix);
	return (flag);
}

int	read_map(char *map_file, int flag)
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
	flag = create_matrix(map_file, flag);
	return (flag);
}

int	main(int ac, char **av)
{
	int				flag;
	size_t			len;
	char			*format;

	flag = 1;
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
			flag = read_map(av[1], flag);
	}
}
