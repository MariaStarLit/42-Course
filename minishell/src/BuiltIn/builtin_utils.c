/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:03 by mde-avel          #+#    #+#             */
/*   Updated: 2024/02/27 16:42:23 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//what is munmap_chunk(): invalid pointer?
void	change_oldpwd(t_list **lst, char *oldpwd)
{
	t_list	*tmp;
	char	*new_cont;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (ft_strcmp((char *)(tmp)->ident, "OLDPWD") == 0)
		{
			new_cont = ft_strdup(oldpwd);
			free((tmp)->content);
			(tmp)->content = new_cont;
			break ;
		}
		tmp = (tmp)->next;
	}
}

char	*get_cont(const char *str, int c)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = -1;
	j = -1;
	while (str[++i])
		if (str[i] == (char)c)
			break ;
	if (i == (int)ft_strlen(str) || str[i + 1] == '\0')
		return (ft_strdup("  "));
	len = ft_strlen(str) - i + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	while (str[i])
		res[++j] = str[++i];
	res[j] = '\0';
	return (res);
}

char	*get_ident(const char *str, int c)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == (char)c)
			break ;
	len = i + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

/**
 * @note Type 1 Creates a new var env
 * @note Type 2 Subs var env
 * @note Type 3 Creates a new var export
 * @note Type 4 Subs var export
*/
int	get_flag(t_minishell *ms, char *ident, char *new_con, char *content)
{
	if (!ft_strchr(content, '='))
	{
		if (find_ident(ms->env, ident, new_con, 2) == 2)
			return (4);
		else if (find_ident(ms->env, ident, new_con, 2) == 1)
			return (0);
		else
			return (3);
	}
	else
	{
		if (find_ident(ms->env, ident, new_con, 1) == 2)
			return (2);
		else
			return (1);
	}
	return (0);
}

//ft_printf("%sident: %s%s\n", YELLOW, head->ident, RESET);
//ft_printf("%scontent: %s%s\n", PURPLE, head->content, RESET);
t_list	*ft_envnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	if (ft_strchr(content, '=') == 0)
		head->equal = 0;
	else
		head->equal = 1;
	head->ident = get_ident(content, '=');
	head->content = get_cont(content, '=');
	head->next = NULL;
	return (head);
}
