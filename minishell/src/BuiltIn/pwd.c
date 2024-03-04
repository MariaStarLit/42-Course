/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:46:30 by dimarque          #+#    #+#             */
/*   Updated: 2023/11/17 10:46:30 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	pwd(void)
{
	int		i;
	char	cwd[PATH_MAX + 1];

	i = 0;
	if (getcwd(cwd, sizeof(cwd)) != NULL) 
	{
		printf("%s\n", cwd);
		while (cwd[i])
			cwd[i++] = 0;
	}
	else
		perror("Minishell$> pwd() error!");
}
