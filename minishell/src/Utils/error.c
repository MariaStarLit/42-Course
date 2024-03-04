/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:58:21 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/25 15:38:34 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	error(t_minishell *ms, int op, char *arg, char *plus)
{
	if (op == 1 && arg != NULL)
	{
		if (plus)
			ft_printf("%s%s%s'%s': ", RED, ms->prompt, RESET, plus);
		else
			ft_printf("%s%s%s", RED, ms->prompt, RESET);
		ft_putstr_fd(arg, 2);
	}
	if (op == 2)
	{
		printf("%s\n", arg);
		ft_putstr_fd("Minishell: error: malloc failed\n", STDERR_FILENO);
		ms->exit = 12;
		free(ms);
		exit(ms->exit);
	}
}

// The function prints an error message with a colored prompt.
void	error_message(t_minishell *ms, char *mess, char *plus)
{
	if (plus)
		ft_printf("%s%s%s'%s': ", RED, ms->prompt, RESET, plus);
	else
		ft_printf("%s%s%s", RED, ms->prompt, RESET);
	ft_putstr_fd(mess, 2);
}

int	open_error(t_minishell *ms, char *filename, int child)
{
	ft_putstr_fd("Minishell: ", STDERR_FILENO);
	perror(filename);
	if (filename)
		free(filename);
	if (child)
	{
		ms->exit = 1;
		free_ms(ms);
	}
	else
	{
		ms->exit = 1;
		return (1);
	}
	return (0);
}

void	pipe_error(t_minishell *ms, int *pipe_fd)
{
	close_fd(pipe_fd);
	ft_putstr_fd("Minishell: error: pipe failed\n", STDERR_FILENO);
	ms->exit = 1;
	free_ms(ms);
}

void	fork_error(t_minishell *ms, int *pipe_fd)
{
	close_fd(pipe_fd);
	ft_putstr_fd("Minishell: error: fork failed\n", STDERR_FILENO);
	ms->exit = 1;
	free_ms(ms);
}
