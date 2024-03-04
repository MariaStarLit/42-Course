/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:33:27 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/07 12:43:40 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Count the number of substrings separated by a delimiter character in a string
 * and optionally populate an array with these substrings
 * 
 * @param str The string to count substrings in
 * @param c The delimiter character used to separate substrings
 * @param list (optional) An array to store the substrings, if provided
 * @return The number of substrings found in the string
 * @note If 'list' is provided, the function also populates it with the
 * substrings found in 'str'
 * @warning If 'list' is provided, ensure it has enough space to store all the
 * substrings
 */
static int	ft_nstr(char const *str, char c, char **list)
{
	int	i;
	int	len;

	i = 0;
	while (*str)
	{
		len = 0;
		while (*str == c && *str)
			str++;
		if (*str)
			i++;
		while (str[len] != c && str[len])
			len++;
		if (list && i && len)
			list[i - 1] = ft_substr(str, 0, len);
		while (*str != c && *str)
			str++;
	}
	return (i);
}

char	**ft_split(char const *str, char c)
{
	char	**token;

	token = ft_calloc(sizeof(char *), (ft_nstr(str, c, NULL) + 1));
	if (!token)
		return (NULL);
	ft_nstr(str, c, token);
	return (token);
}
