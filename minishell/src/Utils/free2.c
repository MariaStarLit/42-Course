/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:18:19 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/25 16:58:54 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free2(char *str, char *str1)
{
	free(str);
	free(str1);
}

void	free_hdoc(t_minishell *ms)
{
	int	exit_status;

	close(0);
	close(1);
	if (ms->fdin != -1)
		close(ms->fdin);
	if (ms->fdout != -1)
		close(ms->fdout);
	if (ms->input)
		free(ms->input);
	if (ms->prompt)
		free(ms->prompt);
	if (ms->main_arr)
		free_arr(ms->main_arr);
	free_list_malloc(ms->env);
	exit_status = ms->exit;
	free(ms);
	rl_clear_history();
	exit (exit_status);
}
