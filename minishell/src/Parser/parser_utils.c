/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:46:37 by dimarque          #+#    #+#             */
/*   Updated: 2023/11/06 11:46:37 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	quotes(char *str, char c, int i)
{
	if (str[i] && str[i] == c)
	{
		i++;
		while (str[i] && str[i] != c)
			i++;
		if (!str[i])
			return (i);
		i++;
		if (str[i] && !parser_op(str[i]))
			return (space_tab(str, i));
		else if (str[i] && str[i] == '$')
			return (envar(str, i));
		else if (str[i] && parser_op(str[i]) == 3)
			return (quotes(str, str[i], i));
	}
	return (i);
}

int	space_tab(char *str, int i)
{
	if (str[i] && !parser_op(str[i]))
	{
		while (str[i] && !parser_op(str[i]))
			i++;
		if (str[i] && str[i] == '$')
			return (envar(str, i));
		else if (str[i] && parser_op(str[i]) == 3)
			return (quotes(str, str[i], i));
	}
	return (i);
}

int	envar(char *str, int i)
{
	if (str[i] == '$')
	{
		i++;
		if (str[i] && parser_op(str[i]) == 3)
			return (quotes(str, str[i], i));
		else if (str[i] && !parser_op(str[i]))
			return (space_tab(str, i));
	}
	return (i);
}

int	others(char *str, int i)
{
	if (str[i] && str[i] == '|')
		i++;
	else if (str[i] == '>')
	{
		i++;
		if (str[i] && (str[i] == '>' || str[i] == '|'))
			i++;
	}
	else if (str[i] == '<')
	{
		i++;
		if (str[i] && (str[i] == '<' || str[i] == '>'))
			i++;
	}
	return (i);
}
