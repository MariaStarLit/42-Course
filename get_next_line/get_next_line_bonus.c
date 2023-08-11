/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:27:37 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/11 13:19:40 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * The function `get_next_line` reads a line from a file descriptor 
 * and returns it as a string.
 */
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

// int	main(void)
// {
// 	int		fd1, fd2;
// 	char	*line;

// 	fd1 = open("text1.txt", O_RDONLY);
// 	fd2 = open("text2.txt", O_RDONLY);
// 	line = get_next_line(fd1);
// 	printf("t1 line 1: %s", line);
// 	free(line);
// 		line = get_next_line(fd2);
// 	printf("t2 line 1: %s", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("t1 line 2: %s", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("t2 line 2: %s", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("t1 line 3: %s", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("t2 line 3: %s", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("t1 line 4: %s", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("t2 line 4: %s", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("t1 line 5: %s", line);
// 	free(line);
// 		line = get_next_line(fd2);
// 	printf("t2 line 5: %s", line);
// 	free(line);
// }
