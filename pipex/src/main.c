/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:42:21 by mde-avel          #+#    #+#             */
/*   Updated: 2023/10/20 18:06:35 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// The function returns a string that represents the directory PATH of the 
// environment variables, to the specified command (cmd). 
// If the command is not found, thefunction returns NULL.
char	*get_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	*tmp;
	char	*env_path;
	char	**split_path;

	env_path = find_path(envp);
	split_path = ft_split(env_path, ':');
	i = 0;
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(path, F_OK) == 0)
		{
			free_matris(split_path);
			return (path);
		}
		free (path);
		i++;
	}
	free_matris(split_path);
	return (NULL);
}

// The function executes the second command to open Outfile.
// Also handles any errors that may occur.
void	second_child(t_var *vars, char **av, char **envp, int *fd_pipe)
{
	close(fd_pipe[1]);
	dup2(fd_pipe[0], STDIN_FILENO);
	close(fd_pipe[0]);
	vars->file2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC);
	if (vars->file2 < 0)
		error_and_exit("Error! Falior opening Outfile.\n");
	dup2(vars->file2, STDOUT_FILENO);
	close(vars->file2);
	vars->cmd2 = ft_split(av[3], ' ');
	vars->path_cmd2 = get_cmd_path(vars->cmd2[0], envp);
	if (vars->path_cmd2 == NULL)
		error_and_exit("Error! Second command not found\n");
	if (execve(vars->path_cmd2, vars->cmd2, envp) < 0)
	{
		free(vars->path_cmd2);
		free_matris(vars->cmd2);
		error_and_exit("Error! Executing second command\n");
	}
}

// The function opens the Infile, executes the first command specified in 
// the arguments to infile and handles any errors that may occur.
void	first_child(t_var *vars, char **av, char **envp, int *fd_pipe)
{
	close(fd_pipe[0]);
	vars->file1 = open(av[1], O_RDONLY);
	if (vars->file1 < 0)
		error_and_exit("Error! Falior opening Infile.\n");
	dup2(vars->file1, STDIN_FILENO);
	close(vars->file1);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[1]);
	vars->cmd1 = ft_split(av[2], ' ');
	vars->path_cmd1 = get_cmd_path(vars->cmd1[0], envp);
	if (vars->path_cmd1 == NULL)
		error_and_exit("Error! First command not found\n");
	if (execve(vars->path_cmd1, vars->cmd1, envp) < 0)
	{
		free(vars->path_cmd1);
		free_matris(vars->cmd1);
		error_and_exit("Error! Executing first command\n");
	}
}

// The main function creates two child processes through fork, uses a pipe
// to communicate between them. Also handles any errors that may occur.
int	main(int ac, char **av, char **envp)
{
	t_var	vars;
	int		fd_pipe[2];

	if (ac != 5)
		error_and_exit("Error! Invalid number os arguments, needs to be 4.\n");
	if (pipe(fd_pipe) < 0)
		error_and_exit("Error! Unable to creat pipe.\n");
	vars.pid1 = fork();
	if (vars.pid1 < 0)
		error_and_exit("Error! Unable to creat first child.\n");
	if (vars.pid1 == 0)
		first_child(&vars, av, envp, fd_pipe);
	close(fd_pipe[1]);
	vars.pid2 = fork();
	if (vars.pid2 < 0)
		error_and_exit("Error! Unable to creat second child.\n");
	if (vars.pid2 == 0)
		second_child(&vars, av, envp, fd_pipe);
	close(fd_pipe[0]);
	waitpid(vars.pid1, NULL, 0);
	waitpid(vars.pid2, NULL, 0);
}
