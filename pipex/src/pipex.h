/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:42:26 by mde-avel          #+#    #+#             */
/*   Updated: 2023/10/20 18:17:20 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h> //perror & fopen
# include <string.h> //strerror
# include <unistd.h> //write & pipe & fork & close & access & dup2 & execve
# include <sys/wait.h> //waitpid
# include <sys/stat.h> //open
# include <sys/types.h> //open & fork & waitpid
# include <fcntl.h> //open
# include <stdlib.h> //malloc & free
# include <stdarg.h> //file
# include <errno.h> //errno

typedef struct s_var
{
	int		pid1;
	int		pid2;
	int		file1;
	int		file2;
	char	*path_cmd1;
	char	*path_cmd2;
	char	**cmd1;
	char	**cmd2;
}	t_var;

// main.c
char	*get_cmd_path(char *cmd, char **envp);
void	second_child(t_var *vars, char **av, char **envp, int *fd_pipe);
void	first_child(t_var *vars, char **av, char **envp, int *fd_pipe);

// utils.c
char	*find_path(char **env);
void	free_matris(char **str);
int		error_and_exit(char *msg);

#endif