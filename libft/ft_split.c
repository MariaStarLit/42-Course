/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:31:26 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:41 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It splits a string into an array of strings.
 * 
 * @param s the string to be split
 * @param c the character to split on
 * 
 * @return A pointer to a pointer to fist string of the array of strings.
 */

static int	numpal(const char *str, char di)
{
	int	i;
	int	flag;
	int	cont;

	i = 0;
	flag = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] != di && flag == 0)
		{
			flag = 1;
			cont++;
		}
		else if (str[i] == di)
		{
			flag = 0;
		}
		i++;
	}
	return (cont);
}

static char	*palavras(const char *s, int start, int end)
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

static char	**to_long(char const *s, char c, size_t len, char **res)
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
			res[j++] = palavras(s, flag, i);
			flag = -1;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**res;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(sizeof(char *) * (numpal(s, c) + 1));
	if (!res)
		return (NULL);
	res = to_long(s, c, len, res);
	return (res);
}

/*int	main(void)
{
	char	s[] = "Porra desta merda de funcao.";
	char	**token = ft_split(s, ' ');

	printf("split: |%s|\n", *token);
}*/
