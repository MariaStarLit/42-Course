/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:31:11 by dimarque          #+#    #+#             */
/*   Updated: 2023/11/17 16:31:11 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	change_pwd(t_list **lst, char *oldpwd)
{
	t_list	*tmp;
	char	pwd[PATH_MAX + 1];

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (ft_strcmp((char *)(tmp)->ident, "PWD") == 0)
		{
			getcwd(pwd, sizeof(pwd));
			free((tmp)->content);
			(tmp)->content = ft_strdup(pwd);
			ft_bzero(pwd, ft_strlen(pwd));
			break ;
		}
		tmp = (tmp)->next;
	}
	change_oldpwd(lst, oldpwd);
}

static void	home_to_dir(t_minishell *ms, char *path)
{
	size_t	len;
	char	*new_path;

	len = ft_strlen(path) - 2;
	new_path = ft_substr(path, 2, len);
	if (chdir(new_path) == -1)
	{
		error(ms, 1, "cd: No such file or directory\n", NULL);
		ms->exit = 1;
	}
	free(new_path);
}

static char	*find_home(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (ft_strcmp((char *)(tmp)->ident, "HOME") == 0)
			return ((tmp)->content);
		tmp = (tmp)->next;
	}
	return (0);
}

static void	go_home(t_minishell *ms)
{
	char	*home;

	home = find_home(ms->env);
	if (!home)
	{
		error(ms, 1, "cd: HOME not set\n", NULL);
		ms->exit = 1;
	}
	else
	{
		if (chdir(home) == -1)
		{
			error(ms, 1, "cd: No such file or directory\n", NULL);
			ms->exit = 1;
		}
	}
}

void	cd(t_minishell *ms, char **path)
{
	char	oldpwd[PATH_MAX + 1];

	getcwd(oldpwd, sizeof(oldpwd));
	if (path && arr_size(path) > 2)
	{
		error(ms, 1, "cd: too many arguments\n", NULL);
		ms->exit = 1;
	}
	else if (!path || !path[1] || !path[1][0])
		go_home(ms);
	else if (path[1][0] == '~' && path)
	{
		go_home(ms);
		if (path[1][1] == '/' && path[1][2])
			home_to_dir(ms, path[1]);
	}
	else if (chdir(path[1]) == -1)
	{
		error(ms, 1, "cd: No such file or directory\n", NULL);
		ms->exit = 1;
	}
	change_pwd(ms->env, oldpwd);
	ft_bzero(oldpwd, ft_strlen(oldpwd));
}
