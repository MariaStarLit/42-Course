/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:45:30 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/25 16:57:47 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*heredoc_output(t_minishell *ms, char *limiter, char *line)
{
	char	*buf;

	buf = remove_quotes(limiter);
	if (g_global == SIGINT || !line || strcmp_nochr(buf, line, '\n') == 0)
	{
		free(buf);
		return (NULL);
	}
	free(buf);
	if (!ft_strchr(limiter, '\'') && !ft_strchr(limiter, '\"'))
		buf = replace_str(ms, line);
	else
		buf = ft_strdup(line);
	return (buf);
}

void	heredoc_child(t_minishell *ms, char *filename, char *limiter)
{
	char	*output;
	char	*line;
	int		fd;

	line = NULL;
	fd = create_file(ms, filename);
	while (1)
	{
		change_terminal();
		line = readline("> ");
		if (g_global == SIGINT)
			ms->exit = 128 + SIGINT;
		else if (!line)
			heredoc_eof(limiter);
		output = heredoc_output(ms, limiter, line);
		if (!output)
			break ;
		free(line);
		ft_putendl_fd(output, fd);
		free(output);
	}
	if (line)
		free(line);
	close(fd);
	free_hdoc(ms);
}

char	*heredoc(t_minishell *ms, char *limiter, int here_num)
{
	char	*filename;
	pid_t	pid;
	int		status;

	signal(SIGINT, SIG_IGN);
	filename = create_filename(here_num);
	pid = fork();
	if (pid < 0)
		fork_error(ms, NULL);
	if (pid == 0)
	{
		signal(SIGINT, heredoc_signal);
		heredoc_child(ms, filename, limiter);
	}
	else
	{
		wait(&status);
		if (pid != -1 && WIFEXITED(status) && WEXITSTATUS(status) == (128 + \
			SIGINT))
		{
			g_global = SIGINT;
			unlink(filename);
		}
	}
	return (filename);
}
