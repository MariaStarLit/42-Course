/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:09:37 by dimarque          #+#    #+#             */
/*   Updated: 2024/01/24 12:09:37 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//Compares env variables with var.
//Returns the value of var if it finds it in env.
// var = HOME
// env: HOME=/home/dmarque
// return: /home/dmarque
char	*var_iter(t_minishell *ms, char *var)
{
	char	*buf;
	t_list	*tmp;

	if (ft_strcmp(var, "?") == 0)
	{
		buf = ft_itoa(ms->exit);
		return (buf);
	}
	tmp = *ms->env;
	while (tmp)
	{
		if (ft_strcmp((tmp)->ident, var) == 0)
			buf = ft_strdup((tmp)->content);
		else
			buf = NULL;
		if (buf)
			return (buf);
		tmp = tmp->next;
		free(buf);
	}
	return (NULL);
}

// equivalent to `env | grep var`
char	*var_str(t_list *env, char *var)
{
	t_list	*tmp;

	tmp = env;
	while (tmp->content)
	{
		if (ft_strncmp((char *)tmp->content, var, ft_strlen(var)) == 0)
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (NULL);
	return (tmp->content);
}
