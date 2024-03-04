/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:40:06 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/26 19:40:06 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//export _=poop A1=Desenhada A2=Banda
//export hi ho hiho
//export A1=Banana A2=Casca_de A3=Macaco_atira
//export hi=bye hi=hello A1=folha ho=

int	valid_ident(char *s)
{
	int	i;
	int	flag;

	if (ft_strcmp(s, "_") == 0)
		return (2);
	if ((s[0] >= '0' && s[0] <= '9') || s[0] == '=')
		return (0);
	i = 0;
	flag = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')
			|| (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '_')
			flag = 1;
		else
			return (0);
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int	find_ident(t_list **env, char *ident, char *new_cont, int flag)
{
	t_list	*tmp;

	tmp = *env;
	if (!tmp)
		perror("Minishell$> export");
	while (tmp)
	{
		if (ft_strcmp((char *)(tmp)->ident, ident) == 0)
		{
			if (flag == 2 && (tmp)->n == 1)
				return (1);
			if (flag == 1 && (tmp)->n == 2)
			{
				(tmp)->n = 1;
				(tmp)->equal = 1;
			}
			free((tmp)->content);
			(tmp)->content = ft_strdup(new_cont);
			free(new_cont);
			free(ident);
			return (2);
		}
		tmp = (tmp)->next;
	}
	return (0);
}

static int	check_identifier(t_minishell *ms, char *content)
{
	char	*ident;
	char	*new_con;
	int		flag;

	flag = 0;
	new_con = get_cont(content, '=');
	ident = get_ident(content, '=');
	if (valid_ident(ident) == 1)
		flag = get_flag(ms, ident, new_con, content);
	else if (valid_ident(ident) == 0)
	{
		error(ms, 1, "export: not a valid identifier\n", ident);
		ms->exit = 1;
	}
	if (flag == 1 || flag == 3 || flag == 0)
	{
		free(ident);
		free(new_con);
	}
	return (flag);
}

static void	ft_export_2(t_minishell *ms, char *content, int check)
{
	t_list	*new;

	if (check == 1)
	{
		new = ft_envnew(content);
		new->n = 1;
		new->equal = 1;
		ft_lstadd_front(ms->env, new);
	}
	if (check == 3)
	{
		new = ft_envnew(content);
		new->n = 2;
		new->equal = 0;
		ft_lstadd_front(ms->env, new);
	}
}

void	ft_export(t_minishell *ms, char **cmd_line)
{
	int		i;
	int		check;
	char	*content;

	i = 1;
	if (!cmd_line[i])
	{
		print_lst(ms->env, 2);
		return ;
	}
	while (cmd_line[i])
	{
		content = ft_strdup(cmd_line[i]);
		check = check_identifier(ms, content);
		ft_export_2(ms, content, check);
		i++;
		free(content);
	}
}
