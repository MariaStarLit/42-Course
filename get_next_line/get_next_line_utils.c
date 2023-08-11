/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:36:21 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/11 18:04:08 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
