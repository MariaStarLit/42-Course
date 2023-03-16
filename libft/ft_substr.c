/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:57:59 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 15:00:48 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns a substring of the string s, starting at index start and of 
 * length len.
 * 
 * @param s The string to be cut
 * @param start the index of the first character to include in the returned 
 * substring'
 * @param len the maximum number of characters to copy
 * 
 * @return A pointer to a new string.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	while (i < len && (start + i) < len_s)
	{
		i++;
	}
	res = ft_calloc(sizeof(char), (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && (start + i) < len_s)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}

/*int	main(void)
{
	char 	fio[] = "ABCDEFG";
	char	*g;

	g = ft_substr (fio, 3, 3);
	printf("minha f: %s\n", g);
}*/
