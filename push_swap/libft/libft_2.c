/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:33:41 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/09 18:12:28 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * It splits a string into an array of strings.
 * 
 * @param s the string to be split
 * @param c the character to split on
 * 
 * @return A pointer to a pointer to fist string of the array of strings.
 */
static int	n_words(char *str, char espace)
{
	int	i;
	int	flag;
	int	cont;

	i = 0;
	flag = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] != espace && flag == 0)
		{
			flag = 1;
			cont++;
		}
		else if (str[i] == espace)
		{
			flag = 0;
		}
		i++;
	}
	return (cont);
}

static char	*words(char *s, int start, int end)
{
	char	*pal;
	int		i;

	i = 0;
	pal = malloc(sizeof(char) * (end - start) + 1);
	if (!pal)
		return (NULL);
	while (start < end)
	{
		pal[i] = s[start];
		i++;
		start++;
	}
	pal[i] = '\0';
	return (pal);
}

static char	**separate(char *s, char c, size_t len, char **res)
{
	size_t	i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = -1;
	while (i <= len)
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || i == len) && flag >= 0)
		{
			res[j++] = words(s, flag, i);
			flag = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char *s, char c)
{
	size_t	len;
	char	**res;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(sizeof(char *) * (n_words(s, c) + 1));
	if (!res)
		return (NULL);
	res = separate(s, c, len, res);
	return (res);
}
