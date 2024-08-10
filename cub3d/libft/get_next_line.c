/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:23:26 by mde-avel          #+#    #+#             */
/*   Updated: 2024/03/04 21:28:24 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function "cleanbuffer" clears the contents of a character buffer.
 * @return NULL.
 */
static char	*cleanbuffer(char *buffer, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	while (buffer[i])
	{
		buffer[i] = 0;
		i++;
	}
	return (NULL);
}

/**
 * The function `ft_strlen_gnl` returns the length of a string until 
 * the first occurrence of a newline character or the end of the string.
 */
static size_t	ft_strlen_gnl(const char *str)
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

// The function `ft_strjoin_gnl` concatenates two strings, `line` and `buffer`, 
// and returns the result.
static char	*ft_strjoin_gnl(char const *line, char const *buffer)
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

static char	*to_long(int flag, char *buffer, int fd)
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			flag;

	flag = 0;
	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (cleanbuffer(buffer[fd], fd));
	line = to_long(flag, buffer[fd], fd);
	return (line);
}

/*
int	main(void)
{
	int		fd1, fd2;
	char	*line;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("t1 line 1: %s", line);
	free(line);
		line = get_next_line(fd2);
	printf("t2 line 1: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("t1 line 2: %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("t2 line 2: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("t1 line 3: %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("t2 line 3: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("t1 line 4: %s", line);
	free(line);
	line = get_next_line(fd2);
	printf("t2 line 4: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("t1 line 5: %s", line);
	free(line);
		line = get_next_line(fd2);
	printf("t2 line 5: %s", line);
	free(line);
}
*/