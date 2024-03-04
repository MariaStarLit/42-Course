/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:10:04 by dimarque          #+#    #+#             */
/*   Updated: 2024/01/24 12:10:04 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// If $? return 2
// If $3 replace with NULL
// While str[i] is alphanumerical or '_' i++
int	get_var_len(char *str)
{
	int	i;

	i = 0;
	if (parser_op(str[i]) != 4)
		return (0);
	i++;
	if (str[i] && (str[i] == '?' || ft_isdigit(str[i])))
		return (2);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

// This function replaces one environment variable with its value
char	*replace_var(t_minishell *ms, char *result, char quotes, int str_index)
{
	char	*var;
	char	*fix;
	char	*buffer;

	var = NULL;
	fix = NULL;
	buffer = NULL;
	fix = ft_strndup(result, str_index);
	if (!(parser_op(result[str_index + 1]) == 3 && !quotes))
		buffer = ft_strndup(result + str_index, \
		get_var_len(result + str_index));
	if (buffer && ft_strcmp(buffer, "$") == 0)
		var = ft_strdup(buffer);
	else if (buffer)
		var = var_iter(ms, buffer + 1);
	free(buffer);
	buffer = ft_strjoin(fix, var);
	free(fix);
	fix = ft_strdup(result + str_index + get_var_len(result + str_index));
	free(var);
	free(result);
	result = ft_strjoin(buffer, fix);
	free(buffer);
	free(fix);
	return (result);
}

size_t	get_new_index(t_minishell *ms, char *result, char quotes, int str_index)
{
	char	*var;
	char	*buffer;
	int		new_index;

	var = NULL;
	buffer = NULL;
	new_index = 0;
	if (!(parser_op(result[str_index + 1]) == 3 && !quotes))
		buffer = ft_strndup(result + str_index, \
		get_var_len(result + str_index));
	if (buffer && ft_strcmp(buffer, "$") == 0)
		var = ft_strdup(buffer);
	else if (buffer)
		var = var_iter(ms, buffer + 1);
	new_index = ft_strlen(var);
	free(buffer);
	free(var);
	return (new_index);
}

//function that replaces a given string. To be used in heredoc.
char	*replace_str(t_minishell *ms, char *str)
{
	int		var_len;
	char	*result;
	char	quotes;
	int		str_index;

	var_len = 0;
	quotes = '\0';
	str_index = 0;
	result = ft_strdup(str);
	while (result && result[str_index])
	{
		if (!quotes && parser_op(result[str_index]) == 3)
			quotes = result[str_index];
		else if (quotes && result[str_index] == quotes)
			quotes = '\0';
		if (result[str_index] == '$' && quotes != '\'')
		{
			var_len = get_new_index(ms, result, quotes, str_index);
			result = replace_var(ms, result, quotes, str_index);
			str_index += var_len - 1;
		}
		str_index++;
	}
	return (result);
}

// This function goes through every string in the main_arr and replaces
// environment variables with their value
// It does not yet move the strings in the array when one is replaced with NULL
char	**replaced_arr(t_minishell *ms)
{
	char	**new_arr;
	char	*result;
	int		new_index;
	int		arr_index;

	result = NULL;
	arr_index = 0;
	new_index = 0;
	new_arr = ft_calloc(sizeof(char *), arr_size(ms->main_arr) + 1);
	while (ms->main_arr[arr_index])
	{
		if (!ft_strchr(ms->main_arr[arr_index], '$'))
		{
			new_arr[new_index] = ft_strdup(ms->main_arr[arr_index]);
			new_index++;
			arr_index++;
			continue ;
		}
		result = replace_str(ms, ms->main_arr[arr_index++]);
		if (result && result[0])
			new_arr[new_index++] = ft_strdup(result);
		free(result);
	}
	new_arr[new_index] = NULL;
	return (new_arr);
}
// Cases to be prepared
// $"HOME" = HOME
// "$"HOME = $HOME
// $3HOME = HOME
