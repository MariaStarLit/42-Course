/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:49:04 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/24 20:38:08 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	quote_num(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (parser_op(str[i]) == 3)
		{
			i = skip_quotes(str, i);
			n += 2;
		}
		else
			i++;
	}
	return (n);
}

int	skip_quotes(char *str, int pos)
{
	char	quote;

	if (parser_op(str[pos]) == 3)
	{
		quote = str[pos++];
		while (str[pos] && str[pos] != quote)
			pos++;
		pos++;
	}
	return (pos);
}

//Removes quotes from str. Used for case echo "'$HOME'"
char	*remove_quotes(char *str)

{
	int		i;
	int		j;
	char	*buf;
	char	quote;

	i = 0;
	j = 0;
	buf = ft_calloc(sizeof(char), (ft_strlen(str) - quote_num(str) + 1));
	while (str[i])
	{
		if (parser_op(str[i]) == 3)
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				buf[j++] = str[i++];
			if (str[i])
				i++;
		}
		else
			buf[j++] = str[i++];
	}
	return (buf);
}

char	**rm_all_quotes(char **cmds)
{
	int		i;
	int		len;
	char	**new;

	i = 0;
	len = 0;
	while (cmds[i])
	{
		len += ft_strlen(cmds[i]) - quote_num(cmds[i]) + 1;
		i++;
	}
	i = 0;
	new = (char **)malloc(sizeof(char *) * len);
	while (cmds[i])
	{
		new[i] = remove_quotes(cmds[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
