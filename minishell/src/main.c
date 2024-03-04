/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:34:57 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/26 17:28:40 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_global = 0;

void	minishell(t_minishell *ms)
{
	int		pipe_fd[2];
	int		cmds_run;
	int		pos;
	pid_t	pid;

	cmds_run = 0;
	pos = 0;
	if (!ms->cmdlist)
		return ;
	signal(SIGQUIT, signal_process_interrupt);
	while (cmds_run < ms->cmd_count)
	{
		if (pipe(pipe_fd) < 0)
			pipe_error(ms, pipe_fd);
		pid = fork();
		if (pid < 0)
			fork_error(ms, pipe_fd);
		if (pid == 0)
			child(ms, pipe_fd, cmds_run, pos);
		else
			parent(ms, pipe_fd, cmds_run, pos);
		pos = find_cmd_pos(ms->main_arr, pos);
		cmds_run++;
	}
	get_exit_status(ms, pid, cmds_run);
}

t_list	**env_init(char **envp)
{
	int		i;
	char	*buf;
	t_list	*node;
	t_list	**env;

	i = 0;
	env = (t_list **)malloc(sizeof(env));
	*env = NULL;
	while (envp[i])
	{
		buf = ft_strdup(envp[i]);
		node = ft_envnew(buf);
		free(buf);
		node->n = 1;
		ft_lstadd_back(env, node);
		i++;
	}
	return (env);
}

void	free_main(t_minishell *ms, int argc, char *argv[])
{
	post_process_signal();
	signal_d(ms);
	free(ms->prompt);
	free(ms->input);
	free_arr(ms->main_arr);
	if (ms->fdin != -1)
		close(ms->fdin);
	if (ms->fdout != -1)
		close(ms->fdout);
	(void)argc;
	(void)argv;
}

int	main(int argc, char *argv[], char **env)
{
	t_minishell	*ms;

	ms = malloc(sizeof(t_minishell));
	if (!ms)
		error(NULL, 2, NULL, NULL);
	ms->env = env_init(env);
	ms->exit = 0;
	while (1)
	{
		signal_init();
		ms->prompt = set_prompt(ms);
		ms->input = readline(ms->prompt);
		if (ft_strlen(ms->input) != 0)
			add_history(ms->input);
		if (ms->input && syntax_error(ms))
			continue ;
		if (!var_init(ms))
		{
			minishell(ms);
			free_cmd_list(ms->cmdlist);
		}
		free_main(ms, argc, argv);
	}
	exit(ms->exit);
}
