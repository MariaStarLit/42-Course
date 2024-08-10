/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjorge-d <fjorge-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:37:21 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/26 16:50:22 by fjorge-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	size_t	len;
	char	*format;
	char	*aux;

	format = ".cub";
	if (ac < 2)
		error_message("Please provide a map.");
	else if (ac == 2)
	{
		len = ft_strlen(av[1]);
		aux = ft_substr(av[1], len - 4, 4);
		if (ft_strcmp(aux, format))
		{
			free(aux);
			error_message("Invalid map format it needs to be: '.cub'");
		}
		else
		{
			free(aux);
			read_map(av[1]);
			start_game();
		}
	}
	else
		error_message("Too many arguments. Only map is needed.");
}
