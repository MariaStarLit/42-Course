/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:36:28 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/11 18:06:08 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdlib.h>
# include <unistd.h>
//# include <stdio.h> //for the main (printf)
//# include <fcntl.h> //for the main (open, O_RDONLY)

// get_next_line.c
char		*get_next_line(int fd);
char		*to_long(int flag, char *buffer, int fd);

// get_next_line_utils.c 
size_t		ft_strlen_gnl(const char *str);
char		*ft_strjoin_gnl(char const *line, char const *buffer);

#endif