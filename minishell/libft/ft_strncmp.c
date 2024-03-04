/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:49:32 by dimarque          #+#    #+#             */
/*   Updated: 2022/11/04 18:15:34 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	if (n == 0)
		return (0);
	if (n != 0)
	{
		a = s1[i];
		b = s2[i];
	}
	while (s1[i] != '\0' && (s1[i] == s2[i]) && n > (i + 1))
	{
		i++;
		a = s1[i];
		b = s2[i];
	}
	return (a - b);
}
