/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:45:54 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/11 13:16:08 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	j;

	if (start >= ft_strlen(s))
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		res = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (start < ft_strlen(s) && s[start] && j < len)
	{
		res[j] = s[start];
		start++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

/* int main()
{
	char src[] = "pastel de nata";

	int start = 7;
	int len = 2;

	char *dest = ft_substr(src, start, len);

	printf("%s\n", dest);

	return (0);
} */