/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:54:55 by mde-avel          #+#    #+#             */
/*   Updated: 2024/02/20 19:55:12 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmdlist	*cmdlist_last(t_cmdlist *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	return (0);
}

void	cmdlist_add_back(t_cmdlist **lst, t_cmdlist *new)
{
	if (cmdlist_last(*lst))
		cmdlist_last(*lst)->next = new;
	else
		*lst = new;
}
