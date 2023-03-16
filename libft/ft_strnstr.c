/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:01:54 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 15:00:35 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the first character of the substring is found in the string, then 
 * check if the rest of the substring is also in the string.
 * 
 * @param big the string to search in
 * @param little the string to find
 * @param len the maximum number of characters to search
 * 
 * @return A pointer to the first occurrence of the substring little in 
 * the string big, or NULL if the substring is not found.
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)&big[i]);
	if (len == 0)
		return (NULL);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)&big[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	l[30] = "NA";
	char	b[30] = "BANANA! XD";
	size_t	n = 10;

	printf ("minha f: %s\n", ft_strnstr(b, l, n));
}*/
