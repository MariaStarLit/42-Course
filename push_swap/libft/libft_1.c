/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:57:57 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/08 17:11:38 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** The function "new_node" creates a new node for a linked list with the 
 * given values.
 * return a pointer to a newly allocated t_lista structure.
 */
t_lista	*new_node(long n, int n_simple)
{
	t_lista	*new;

	new = (t_lista *)malloc(sizeof(t_lista));
	if (!new)
		return (NULL);
	new->n = n;
	new->n_simple = n_simple;
	new->next = NULL;
	return (new);
}

// The function 'ft_lstadd_front' adds a new element to the 
// front of a linked list.
void	ft_lstadd_front(t_lista **lst, t_lista *new)
{
	t_lista	*tmp;

	tmp = NULL;
	if (lst)
	{
		tmp = *lst;
		*lst = new;
		(*lst)->next = tmp;
	}
	*lst = new;
}

// The function 'ft_lstadd_back' adds a new element to the end of a linked list.
void	ft_lstadd_back(t_lista **lst, t_lista *new)
{
	t_lista	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// The function 'ft_lstlast' returns a pointer to the last element of 'lst'.
// Return the last node of the linked list.
t_lista	*ft_lstlast(t_lista *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// The function 'ft_lstsize' calculates the size of a linked list.
// Return the number of elements in the linked list.
int	ft_lstsize(t_lista *lst)
{
	int		count;
	t_lista	*tmp;

	count = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	free(tmp);
	return (count);
}
