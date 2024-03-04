/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:15:42 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/11 17:24:46 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1) - 1;
	while (s1[len] && ft_strrchr(set, s1[len]))
		len--;
	if (len < 0)
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	return ((char *)res);
}

/* int	main(void)
{
	char str1[] = "aabbccteasteaabbccc";
	char *set = "abc";

	printf("%s\n", ft_strtrim(str1, set));

	return (0);
} */