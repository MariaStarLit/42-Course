/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:48:56 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:49 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * (strcpy with maloloc)
 * It allocates memory for a copy of the string str, copies the string into 
 * the allocated memory, and returns a pointer to it. 
 * 
 * @param str The string to be copied.
 * 
 * @return A pointer to a new string that is a duplicate of the string 
 * passed as argument.
 */

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	res = malloc(sizeof(const char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*int	main(void)
{
	const char	*fio = "Helloworld";
	char		*result;

	result = strdup(fio);
	printf("strdup: //%s//\n", result);
	result = ft_strdup(fio);
	printf("Minhaf: //%s//\n", result);
}
if (!str)
		return (NULL);
*/
