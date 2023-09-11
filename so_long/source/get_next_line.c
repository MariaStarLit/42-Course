/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:36:25 by mde-avel          #+#    #+#             */
/*   Updated: 2023/09/09 12:31:14 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

// The function `ft_strjoin_gnl` concatenates two strings, `line`
// and `buffer`, and returns the result.
char	*ft_strjoin_gnl(char const *line, char const *buffer)
{
	char	*res;
	int		i;
	int		j;
	size_t	len_l;
	size_t	len_b;

	if (!buffer)
		return (NULL);
	i = -1;
	j = -1;
	len_l = ft_strlen_gnl(line);
	len_b = ft_strlen_gnl(buffer);
	res = malloc(sizeof(char) * (len_l + len_b) + 1);
	if (!res)
		return (NULL);
	while (++i < (int)len_l)
		res[i] = line[i];
	while (++j < (int)len_b)
	{
		res[i] = buffer[j];
		i++;
	}
	res[i] = '\0';
	free((void *)line);
	return (res);
}

// The function `get_next_line` reads a line from a file descriptor
// and returns it as a string.
char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	line = NULL;
	if ((read(fd, 0, 0) < 0) || BUFFER_SIZE < 1)
	{
		while (buffer[i])
		{
			buffer[i] = 0;
			i++;
		}
		return (NULL);
	}
	line = to_long(flag, buffer, fd);
	return (line);
}

char	*to_long(int flag, char *buffer, int fd)
{
	size_t		i;
	size_t		j;
	char		*line;

	line = NULL;
	while (!flag && (buffer[0] || read(fd, buffer, BUFFER_SIZE)))
	{
		i = 0;
		j = 0;
		line = ft_strjoin_gnl(line, buffer);
		while (buffer[i])
		{
			if (flag)
			{
				buffer[j] = buffer[i];
				j++;
			}
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i] = 0;
			i++;
		}
	}
	return (line);
}
