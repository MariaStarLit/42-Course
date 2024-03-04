/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:11:44 by dimarque          #+#    #+#             */
/*   Updated: 2024/01/24 12:11:44 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**special_path(const char *cmd)
{
	char	**paths;
	char	buf[PATH_MAX + 1];

	paths = malloc(sizeof(char *) * 2);
	ft_bzero(buf, PATH_MAX + 1);
	if (ft_strncmp(cmd, "../", 3) == 0 || ft_strncmp(cmd, "./", 2) == 0)
	{
		if (getcwd(buf, sizeof(buf)) == NULL)
		{
			free(paths);
			return (NULL);
		}
		paths[0] = ft_strjoin(buf, "/");
		ft_bzero(buf, ft_strlen(buf));
	}
	if (cmd[0] == '/')
		paths[0] = ft_strjoin(NULL, "/");
	paths[1] = NULL;
	return (paths);
}

void	list_print(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		ft_putendl_fd((char *)tmp->content, 1);
		tmp = tmp->next;
	}
}

char	**get_paths(t_list **env, char *cmd)
{
	t_list	*tmp;
	char	**paths;
	char	**path_dir;
	int		i;

	if (ft_strncmp(cmd, "../", 3) == 0 || ft_strncmp(cmd, "./", 2) == 0 \
		|| cmd[0] == '/')
		return (special_path(cmd));
	tmp = *env;
	while (tmp && strncmp(tmp->ident, "PATH", 4) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	paths = ft_split(tmp->content + 5, ':');
	path_dir = malloc(sizeof(char *) * (arr_size(paths) + 1));
	i = 0;
	while (i < arr_size(paths))
	{
		path_dir[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	path_dir[i] = NULL;
	free_arr(paths);
	return (path_dir);
}

char	*get_cmd_path(t_minishell *ms, char **paths, char *cmd)
{
	char	*buf1;
	char	*buf2;
	int		i;

	i = 0;
	while (paths && paths[i])
	{
		buf1 = ft_strjoin(paths[i], "/");
		buf2 = ft_strjoin(buf1, cmd);
		free(buf1);
		if (access(buf2, 0) == 0)
			return (buf2);
		free(buf2);
		i++;
	}
	ms->exit = 127;
	if (strchr(cmd, '/'))
		perror(cmd);
	else if (ft_strcmp(cmd, "\'\'") != 0 && ft_strcmp(cmd, "\"\"") != 0)
	{
		write(STDERR_FILENO, "Minishell: ", 11);
		ft_putstr_fd(cmd, STDERR_FILENO);
		write(STDERR_FILENO, ": command not found\n", 20);
	}
	return (NULL);
}

void	exec(t_minishell *ms, char **cmd_arr, char	**new_cmds)
{
	char	**paths;
	char	*cmd_path;
	char	**env;

	if (!cmd_arr || !cmd_arr[0] || !cmd_arr[0][0])
		write(STDERR_FILENO, "Minishell: '': command not found\n", 33);
	if (isbuiltin(cmd_arr[0]))
		built_in(ms, cmd_arr);
	if (g_global == SIGPIPE)
		free_ms(ms);
	if (!cmd_arr || !cmd_arr[0] || !cmd_arr[0][0] || isbuiltin(cmd_arr[0]))
		free_ms(ms);
	paths = get_paths(ms->env, cmd_arr[0]);
	if (is_exec(ms, cmd_arr[0], paths) == 0)
		free_ms(ms);
	cmd_path = get_cmd_path(ms, paths, cmd_arr[0]);
	free_arr(paths);
	if (!cmd_path)
		free_ms(ms);
	env = list_to_array(ms, ms->env);
	new_cmds = rm_all_quotes(cmd_arr);
	execve(cmd_path, new_cmds, env);
	free(cmd_path);
	ms->exit = errno;
	free_ms(ms);
}
