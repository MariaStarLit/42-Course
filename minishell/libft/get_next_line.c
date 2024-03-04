/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:15:41 by dimarque          #+#    #+#             */
/*   Updated: 2023/09/05 14:58:35 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;

	line = NULL;
	if (read(fd, NULL, 0) < 0)
		return (ctrl_l(buffer));
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		line = ft_strjoin(line, buffer);
		i = 0;
		j = -1;
		while (buffer[i])
		{
			if (j != -1)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n' && j == -1)
				j = 0;
			buffer[i++] = 0;
		}
		if (line[ft_strlen_gnl(line) - 1] == '\n')
			break ;
	}
	return (line);
}

/* int main(void)
{
	int fd;
	char *line;
	fd = open("test.txt", O_RDONLY);
	//printf("%s", get_next_line(fd));
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
} */