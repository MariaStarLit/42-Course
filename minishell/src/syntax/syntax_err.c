/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:33:40 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/23 16:49:57 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Checks for >< and <|
int	redir_syntax(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str) - 1;
	while (i < size && str[i])
	{
		while (str[i] && str[i] != '>' && str[i] != '<' \
			&& parser_op(str[i]) != 3)
			i++;
		if (i < size && str[i] && parser_op(str[i]) == 3)
			i = skip_quotes(str, i);
		if (i < size && str[i] && str[i + 1] && (str[i] == '>' \
				&& str[i + 1] == '<'))
			return (token_message(str[i + 1]));
		if (i < size && str[i] && str[i + 1] && (str[i] == '<' \
				&& str[i + 1] == '|'))
			return (token_message(str[i + 1]));
		i++;
	}
	return (0);
}

//Checks for << | and for >> |
int	double_redir_syntax(char *str)
{
	char	redir;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(str) - 1;
	while (i < size)
	{
		while (i < size && parser_op(str[i]) != 3 && str[i] != '>' \
				&& str[i] != '<')
			i++;
		if (i < size && str[i] && parser_op(str[i]) == 3)
			i = skip_quotes(str, i);
		if (i < size && str[i] && i < size && (str[i] == '>'
				|| str[i] == '<'))
		{
			redir = str[i];
			if (i < size && str[i + 1] == redir && (str[i + 2] == '|'
					|| (str[i + 2] == ' ' \
					&& str[i + 3] == '|')))
				return (token_message('|'));
		}
		i++;
	}
	return (0);
}

int	dollar_syntax(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (!str[i])
				break ;
			i++;
		}
		else if (str[i] == '$' && str[i + 1] == '$')
			return (token_message('$'));
		else
			i++;
	}
	return (0);
}

//Checks if there are any >, < or | in sucession (divided by whitespace)
//Example: hello > > world; hello > | world: hello > < world
int	sucession_syntax(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str) - 1;
	while (i < size)
	{
		while (str[i] && str[i] != '<' && str[i] != '>' \
			&& parser_op(str[i]) != 3)
			i++;
		if (str[i] && i < size && parser_op(str[i]) == 3)
			i = skip_quotes(str, i);
		if (str[i] && (str[i] == '<' || str[i] == '>'))
		{
			i++;
			if (str[i] && i < size && parser_op(str[i]) == 1)
			{
				while (str[i] && i < size && parser_op(str[i]) == 1)
					i++;
				if (str[i] && parser_op(str[i]) == 2)
					return (token_message(str[i]));
			}
		}
	}
	return (0);
}

int	token_syntax(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < (int)ft_strlen(str))
	{
		if (parser_op(str[i]) == 3)
			i += skip_quotes(str, i);
		if (i < (int)ft_strlen(str) && (str[i] == '&' || str[i] == '(' \
			|| str[i] == ')' || str[i] == ';'))
			c = str[i];
		i++;
	}
	if (c != 0)
		return (token_message(c));
	return (0);
}
