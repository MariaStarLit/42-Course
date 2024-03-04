/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:11:10 by dimarque          #+#    #+#             */
/*   Updated: 2024/01/24 12:11:10 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	redirect_in(t_minishell *ms, char *file, int heredoc, int child)
{
	int		fd;
	char	*file_buf;

	file_buf = remove_quotes(file);
	fd = open(file_buf, O_RDONLY);
	if (fd < 0)
		return (open_error(ms, file_buf, child));
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		if (heredoc)
			unlink(file_buf);
	}
	free(file_buf);
	return (0);
}

int	redirect_out(t_minishell *ms, char *file, int append, int child)
{
	int		fd;
	char	*file_buf;

	file_buf = remove_quotes(file);
	if (!append)
		fd = open(file_buf, O_CREAT | O_RDWR | O_TRUNC, 0664);
	else
		fd = open(file_buf, O_CREAT | O_RDWR | O_APPEND, 0664);
	if (fd < 0)
		return (open_error(ms, file_buf, child));
	else
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	free(file_buf);
	return (0);
}

void	reset_fds(t_minishell *ms)
{
	dup2(ms->fdout, STDOUT_FILENO);
	dup2(ms->fdin, STDIN_FILENO);
	close(ms->fdout);
	close(ms->fdin);
}

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	redirect(t_minishell *ms, char **main_arr, int pos, int child)
{
	int	index;
	int	error;

	index = pos;
	error = 0;
	while (main_arr[index] && main_arr[index][0] && ft_strcmp(main_arr[\
		index], "|") != 0)
	{
		if (ft_strcmp(main_arr[index], "<") == 0)
			error = redirect_in(ms, main_arr[index + 1], 0, child);
		else if (ft_strcmp(main_arr[index], "<<") == 0)
			error = redirect_in(ms, main_arr[index + 1], 1, child);
		else if (ft_strcmp(main_arr[index], ">") == 0)
			error = redirect_out(ms, main_arr[index + 1], 0, child);
		else if (ft_strcmp(main_arr[index], ">>") == 0)
			error = redirect_out(ms, main_arr[index + 1], 1, child);
		index++;
		if (error)
			return (1);
	}
	return (0);
}
