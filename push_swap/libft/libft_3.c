/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:40:03 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/10 13:08:38 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_atoi function converts a string representation of an integer
// to its corresponding long integer value.
long	ft_atoi(char *s)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	if (s[0] == '+')
		i++;
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res * sign);
}

/**
 * It takes a pointer to a string and a size_t, and sets the first n bytes of 
 * the string to 0.
 * 
 * eptys the string. Exept if n = 0, it does nothing.
 */
void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*res;

	res = str;
	i = 0;
	while (i < n)
	{
		res[i] = 0;
		i++;
	}
	str = res;
}

// It allocates memory for an array. Then the memory is set to zero.
// @return A pointer to the allocated memory.
void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ma;

	ma = malloc(nitems * size);
	if (!ma)
	{
		return (NULL);
	}
	ft_bzero(ma, nitems * size);
	return (ma);
}

//(strcpy with maloloc)
char	*ft_strdup(char *str)
{
	char	*res;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	res = malloc(sizeof(char) * len + 1);
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
