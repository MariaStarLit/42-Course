/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:12:42 by dimarque          #+#    #+#             */
/*   Updated: 2024/01/24 12:12:42 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	rm_first(t_list **env)
{
	t_list	*tmp;

	tmp = *env;
	(*env) = (*env)->next;
	free(tmp->ident);
	free(tmp->content);
	free(tmp);
}

static void	rm_nodes(t_list **env, char *ident)
{
	t_list	*tmp;
	t_list	*lst;

	lst = *env;
	tmp = lst;
	if (!lst)
		return ;
	while (lst->next != NULL)
	{
		if (ft_strcmp((char *)(tmp)->ident, ident) == 0)
		{
			rm_first(env);
			break ;
		}
		else if (ft_strcmp((char *)(lst)->next->ident, ident) == 0)
		{
			tmp = lst->next;
			lst->next = lst->next->next;
			free(tmp->ident);
			free(tmp->content);
			free(tmp);
			break ;
		}
		lst = lst->next;
	}
}

void	unset(t_minishell *ms, char **cmd_line)
{
	int	i;
	int	flag;

	i = 1;
	if (!cmd_line[i])
		return ;
	while (cmd_line[i])
	{
		flag = valid_ident(cmd_line[i]);
		if (flag == 2)
			i++;
		if (flag == 0)
			break ;
		rm_nodes(ms->env, cmd_line[i]);
		i++;
	}
}
