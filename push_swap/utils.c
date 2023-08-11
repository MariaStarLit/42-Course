/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:26:53 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/10 17:49:33 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The function creates a new node with a given value and adds it to the 
// front of a linked list. 
void	create_lst_a(char *s, t_lista **a)
{
	long	n;
	t_lista	*new;

	n = ft_atoi(s);
	new = new_node(n, 0);
	ft_lstadd_front(a, new);
}

// The function `free_lst` frees the memory allocated for a linked list.
void	free_lst(t_lista **lst)
{
	t_lista	*tmp;

	if (lst && *lst)
	{
		while (*lst != NULL)
		{
			tmp = (*lst);
			(*lst) = (*lst)->next;
			free(tmp);
		}
	}
}

// Frees the memory allocated of "s" a array of strings.
void	free_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

// The function "exit_prog" frees memory and exits the program.
void	exit_prog(t_lista **a, t_lista **b, char **s)
{
	free_str(s);
	free_lst(a);
	free_lst(b);
	exit(0);
}
