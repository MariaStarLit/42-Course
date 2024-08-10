/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:39:08 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/27 19:15:13 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_map_elements(int i, int l, size_t len)
{
	while (l < map()->n_lines - 1)
	{
		i = 0;
		len = ft_strlen(map()->matrix[l]);
		while (i < (int)len)
		{
			if (map()->matrix[l][i] != '1' && map()->matrix[l][i] != '0' && \
				map()->matrix[l][i] != 'N' && map()->matrix[l][i] != 'S' && \
				map()->matrix[l][i] != 'E' && map()->matrix[l][i] != 'W' && \
				map()->matrix[l][i] != ' ' && map()->matrix[l][i] != '\n')
				return (1);
			if (map()->matrix[l][i] == 'N' || map()->matrix[l][i] == 'S' || \
				map()->matrix[l][i] == 'E' || map()->matrix[l][i] == 'W' )
			{
				if (map()->player == 0)
					map()->player = (int)map()->matrix[l][i];
				else
					return (1);
			}
			i++;
		}
		l++;
	}
	return (0);
}

static int	check_walls(int i)
{
	int	l;

	l = map()->n_lines - 1;
	while (map()->matrix[0][i] == ' ' || map()->matrix[0][i] == '1')
		i++;
	if (map()->matrix[0][i] != '\n')
		return (1);
	i = 0;
	while (map()->matrix[l][i] == '1' || map()->matrix[l][i] == ' ')
		i++;
	if (map()->matrix[l][i] != '\0')
	{
		printf("Hey!\n");
		return (1);
	}
	return (0);
}

static int	check_line(int l, int i, size_t	len, int flag)
{
	len = ft_strlen(map()->matrix[l]);
	if (flag == 2 && i - 1 >= 0)
	{
		if (map()->matrix[l][i - 1] == ' ')
			return (1);
	}
	else if (flag == 2 && i - 1 < 0)
		return (1);
	if (i < (int)len)
	{
		if (map()->matrix[l][i] == ' ' || map()->matrix[l][i] == '\n' || \
			map()->matrix[l][i] == '\0')
			return (1);
	}
	else
		return (1);
	if (flag == 2 && i + 1 < (int)len)
	{
		if (map()->matrix[l][i + 1] == ' ' || map()->matrix[l][i + 1] == '\n' \
			|| map()->matrix[l][i + 1] == '\0')
			return (1);
	}
	else if (flag == 2 && i + 1 >= (int)len)
		return (1);
	return (0);
}

static int	check_walls_closed(int l, int i)
{
	size_t	len;

	while (l < map()->n_lines - 1)
	{
		i = 0;
		len = ft_strlen(map()->matrix[l]);
		while (i < (int)len)
		{
			if (map()->matrix[l][0] == '\n')
				return (1);
			if (map()->matrix[l][i] == '0' || \
				map()->matrix[l][i] == map()->player)
			{
				if (check_line(l - 1, i, len, 0) || check_line(l, i, len, 2)
					|| check_line(l + 1, i, len, 0))
					return (1);
			}
			i++;
		}
		l++;
	}
	return (0);
}

//Verificar se o player nao tem espacoes vazios ao lado
int	check_map(void)
{
	if (check_map_elements(0, 0, 0) == 1)
		return (1);
	if (check_walls(0) == 1)
		return (1);
	if (check_walls_closed(1, 0) == 1)
		return (1);
	if (map()->player == 0)
		return (1);
	return (0);
}
