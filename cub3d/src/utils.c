/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:03 by mde-avel          #+#    #+#             */
/*   Updated: 2024/06/27 19:07:35 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	*map(void)
{
	static t_data	data;

	return (&data);
}

t_img	*img(void)
{
	static t_img	data;

	return (&data);
}

int	get_mlx_pixel(t_img_data *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

int	check_tab(int i)
{
	while (i < 6)
	{
		if (map()->tab_graf[i] == 1)
			i++;
		else
			return (1);
	}
	return (0);
}

int	find_trash(char *line)
{
	int		len;
	int		i;

	i = 0;
	if (!line)
		return (1);
	len = ft_strlen(line);
	if (!(ft_strnstr(line, "F", len) || ft_strnstr(line, "C", len) || \
		ft_strnstr(line, "NO", len) || ft_strnstr(line, "SO", len) || \
		ft_strnstr(line, "EA", len) || ft_strnstr(line, "WE", len)) && \
			len != 1)
	{
		free(line);
		return (1);
	}
	return (0);
}
