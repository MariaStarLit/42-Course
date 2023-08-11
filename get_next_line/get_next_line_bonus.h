/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:18:36 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/11 13:19:56 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
//# include <fcntl.h> // for the main (open, O_RDONLY)

// get_next_line_bonus.c
char	*get_next_line(int fd);
char	*to_long(int flag, char *buffer, int fd);

// get_next_line_utils_bonus.c
char	*cleanbuffer(char *buffer, int fd);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char const *line, char const *buffer);

#endif