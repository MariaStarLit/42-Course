/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:13:04 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/23 16:49:57 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Checks for unclosed quote marks
int	quote_syntax(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str && str[i])
	{
		if (parser_op(str[i]) == 3)
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				i++;
			if (!str[i])
			{
				write(2, "MiniShell: syntax error: unclosed quote marks\n", 46);
				return (1);
			}
		}
		if (str[i])
			i++;
	}
	return (0);
}

int	pipe_syntax(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && parser_op(str[i]) == 3)
			i = quotes(str, str[i], i);
		else if (str[i] && str[i] == '|')
		{
			i++;
			while (str[i] && parser_op(str[i]) == 1)
				i++;
			if (str[i] && str[i] == '|')
				return (token_message('|'));
		}
		else
			i++;
	}
	return (0);
}

//Checks for metachar at the start of str
int	start_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i] && parser_op(str[i]) == 1)
		i++;
	if (str[i] && str[i] == '|')
		return (token_message(str[i]));
	return (0);
}

//Checks for metachar at the end of str
int	end_syntax(char *str)
{
	int	pos;

	pos = ft_strlen(str) - 1;
	while (pos >= 0)
	{
		if (str[pos] && (str[pos] == '<' || str[pos] == '>'
				|| str[pos] == '|'))
			return (write(2, \
			"MiniShell: syntax error near unexpected token `newline'\n", 56));
		else if (parser_op(str[pos]) == 1)
			pos--;
		else
			break ;
	}
	return (0);
}

int	syntax_error(t_minishell *ms)
{
	if (quote_syntax(ms->input) || pipe_syntax(ms->input) || \
		start_syntax(ms->input) || end_syntax(ms->input) || \
		redir_syntax(ms->input) || double_redir_syntax(ms->input) || \
		dollar_syntax(ms->input) || sucession_syntax(ms->input) || \
		token_syntax(ms->input))
	{
		free(ms->prompt);
		free(ms->input);
		ms->exit = 2;
		return (1);
	}
	return (0);
}
