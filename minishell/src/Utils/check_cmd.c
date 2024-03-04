/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:31:03 by dimarque          #+#    #+#             */
/*   Updated: 2023/11/17 16:31:03 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	isbuiltin(char *str)
{
	if (!str)
		return (0);
	if ((ft_strcmp(str, "echo") == 0) || \
	(ft_strcmp(str, "pwd") == 0) || \
	(ft_strcmp(str, "cd") == 0) || \
	(ft_strcmp(str, "env") == 0) || \
	(ft_strcmp(str, "exit") == 0) || \
	(ft_strcmp(str, "unset") == 0) || \
	(ft_strcmp(str, "export") == 0))
		return (1);
	return (0);
}

void	built_in(t_minishell *ms, char **cmd_flags)
{
	char	**new_cmds;

	ms->exit = 0;
	new_cmds = rm_all_quotes(cmd_flags);
	if (ft_strcmp(new_cmds[0], "cd") == 0)
		cd(ms, new_cmds);
	else if (ft_strcmp(new_cmds[0], "echo") == 0)
		ft_echo(new_cmds);
	else if (ft_strcmp(new_cmds[0], "env") == 0)
		env(ms);
	else if (ft_strcmp(new_cmds[0], "exit") == 0)
		ft_exit(ms, new_cmds);
	else if (ft_strcmp(new_cmds[0], "export") == 0)
		ft_export(ms, new_cmds);
	else if (ft_strcmp(new_cmds[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(new_cmds[0], "unset") == 0)
		unset(ms, new_cmds);
	free_arr(new_cmds);
}
