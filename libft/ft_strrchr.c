/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:21:31 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 15:00:39 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns a pointer to the LAST occurrence of the character c in the 
 * string str.
 * 
 * @param str This is the string to be searched.
 * @param c The character to search for.
 * 
 * @return A pointer to the last occurrence of the character c in the 
 * string str.
 */

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (char)c)
		{
			return ((char *)(str + len));
		}
		len--;
	}
	return (NULL);
}

/*int	main(void)
{
	int	l = '.';
	const char	fio[20] = "Porra. merda. fu";

	printf("minhaf: %s \n", ft_strrchr(fio, l));
	printf("strchr: %s \n", strrchr(fio, l));
}
if (!str)
		return (NULL);
*/
