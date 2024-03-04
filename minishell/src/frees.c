/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:04:11 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/27 16:38:48 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}

void	free_list_malloc(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		if (tmp->ident)
			free(tmp->ident);
		if (tmp->content)
			free(tmp->content);
		if (tmp)
			free(tmp);
	}
	if (list)
		free(list);
}

void	free_cmd_list(t_cmdlist *cmdlist)
{
	t_cmdlist	*tmp;
	t_cmdlist	*head;

	head = cmdlist;
	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->cmds)
			free(tmp->cmds);
		free(tmp);
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

void	free_ms(t_minishell *ms)
{
	int	e;

	e = ms->exit;
	close(0);
	close(1);
	close(2);
	if (ms->fdin != -1)
		close(ms->fdin);
	if (ms->fdout != -1)
		close(ms->fdout);
	if (ms->prompt)
		free(ms->prompt);
	if (ms->input)
		free(ms->input);
	if (ms->main_arr)
		free_arr(ms->main_arr);
	free_list_malloc(ms->env);
	if (ms->cmdlist)
		free_cmd_list(ms->cmdlist);
	free(ms);
	rl_clear_history();
	exit(e);
}
