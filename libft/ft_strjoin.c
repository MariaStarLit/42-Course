/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:34:22 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:58 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * (strcat with malloc)
 * It takes two strings, and returns a new string that is the concatenation 
 * of the two strings.
 * 
 * @param s1 The first string to be joined.
 * @param s2 the string to be appended to s1.
 * 
 * @return A pointer to a new string that is the result of the concatenation
 * of s1 and s2.
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

/*int	main(void)
{
	char str[7] = "_Merda";
	char dst[20] = "Olha";

	printf("strjoin: %s \n", ft_strjoin(dst, str));
}*/
