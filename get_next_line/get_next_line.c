/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:36:25 by mde-avel          #+#    #+#             */
/*   Updated: 2023/01/09 15:44:58 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
//printf("buffer: |%s|\n", buffer);
//printf("line: |%s|\n", line);

// int	main(void)
// {
// 	int		fd1;
// 	char	*line;

// 	fd1 = open("text1.txt", O_RDONLY);
// 	line = get_next_line(fd1);
// 	printf("t1 line 1: %s", line);
// 	free(line);
// 		line = get_next_line(fd1);
// 	printf("t1 line 2: %s", line);
// 	free(line);
// 		line = get_next_line(fd1);
// 	printf("t1 line 3: %s", line);
// 	free(line);
// 		line = get_next_line(fd1);
// 	printf("t1 line 4: %s", line);
// 	free(line);
// 		line = get_next_line(fd1);
// 	printf("t1 line 5: %s", line);
// 	free(line);
// }
