/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:09:01 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 15:00:42 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns a copy of the string given as argument without whitespaces at 
 * the beginning or at the end of the string. Whitespaces are defined by the
 * set argument.
 * 
 * @param s1 The string to be trimmed.
 * @param set the set of characters to trim.
 * 
 * @return A pointer to a new string.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	len = ft_strlen(s1 + i);
	if (len)
	{
		while (s1[i] && ft_strchr(set, s1[len + i - 1]))
			len--;
	}
	res = ft_substr(s1, i, len);
	return (res);
}

/*int	main(void)
{
	char	sopa[] = "&&*&**& PORRA* *&*&&";
	char	come [] = "*&";

	printf("strtrim: ||%s||\n", ft_strtrim(sopa, come));
}*/
