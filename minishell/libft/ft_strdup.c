/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:16:24 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/07 15:48:25 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		strlen;
	char	*str1;

	if (!str)
		return (NULL);
	strlen = ft_strlen(str);
	str1 = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!str1)
		return (NULL);
	ft_strlcpy(str1, str, strlen + 1);
	return (str1);
}

/* int main() {

	printf("%s",ft_strdup("leite"));

	return 0;
}
 */