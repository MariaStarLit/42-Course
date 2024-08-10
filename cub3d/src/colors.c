/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:37:02 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/27 13:53:39 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_color(char *color, int i, int j, int k)
{
	while (ft_isdigit(color[i]))
		i++;
	j = i;
	if (i > 0 && color[i] == ',')
		i++;
	k = i;
	if (i == j + 1)
		while (ft_isdigit(color[i]))
			i++;
	j = i;
	if (i > k && color[i] == ',')
		i++;
	k = i;
	if (i == j + 1)
		while (ft_isdigit(color[i]))
			i++;
	if (i > k && color[i] == '\0')
		return (0);
	return (1);
}

static int	ft_color(char *str, char *info, int tab)
{
	char	*color;

	color = ft_strtrim(str, info);
	free(info);
	if (check_color(color, 0, 0, 0))
	{
		free(color);
		return (1);
	}
	map()->graphics[tab] = ft_strdup(color);
	free(color);
	return (0);
}

static int	get_color(char *color, int tab)
{
	char	*info;

	if (map()->tab_graf[tab] == 1)
	{
		map()->tab_graf[tab] = 2;
		return (1);
	}
	map()->tab_graf[tab] = 1;
	if (tab == 4)
		info = ft_strdup("F \n");
	if (tab == 5)
		info = ft_strdup("C \n");
	if (ft_color(color, info, tab))
		return (1);
	return (0);
}

int	set_rgb_color(char *color)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	i = 0;
	red = ft_atoi(color);
	while (color[i] != ',')
		i++;
	i++;
	green = ft_atoi(color + i);
	while (color[i] != ',')
		i++;
	i++;
	blue = ft_atoi(color + i);
	if (red > 255 || green > 255 || blue > 255)
		return (-1);
	return (red << 16 | green << 8 | blue);
}
// return ((red * 65536) + (green * 256) + blue);

//ft_printf("%sline:%s %s", GREEN, RESET, line);
int	find_colors(char *line, size_t	len, int flag)
{
	int	i;

	i = 1;
	if (line[i] != ' ')
		return (1);
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return (1);
	if (ft_strnstr(line, "F ", len))
		flag = get_color(line, 4);
	if (ft_strnstr(line, "C ", len))
		flag = get_color(line, 5);
	return (flag);
}
