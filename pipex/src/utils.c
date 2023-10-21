/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:26:01 by mde-avel          #+#    #+#             */
/*   Updated: 2023/10/20 17:59:25 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Finds the PATH string in the "envp" text
char	*find_path(char **env)
{
	while (ft_strncmp("PATH=", *env, 5))
		env++;
	return (*env + 5);
}

// Frees the memory of a duble pointer
void	free_matris(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// Prints an error message and exits the program.
int	error_and_exit(char *msg)
{
	perror(msg);
	exit(1);
}
