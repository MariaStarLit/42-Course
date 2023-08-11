/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:50:49 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/10 17:53:37 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_lst(t_lista **lst, char c)
// {
// 	t_lista	*tmp;

// 	tmp = *lst;
// 	ft_printf("list %c: ", c);
// 	if (!tmp)
// 	{
// 		ft_printf("Error!!!\n");
// 		return ;
// 	}
// 	while (tmp)
// 	{
// 		ft_printf("%d ", (tmp)->n);
// 		tmp = (tmp)->next;
// 	}
// 	ft_printf("\n");
// }

/**
 * The function "push_swap" takes an array of strings as input, creates two
 * stacks, and then sorts the elements in the stacks using either the
 * "sort_small" or "sort_big" function depending on the length of the input
 *  array, before finally exiting the program.
 */
void	push_swap(char **s)
{
	t_stack	stack;
	int		len;
	int		i;

	stack.a = NULL;
	stack.b = NULL;
	len = array_len(s);
	i = len - 1;
	while (i >= 0)
	{
		create_lst_a(s[i], &stack.a);
		i--;
	}
	if (len <= 5)
		sort_small(&stack.a, &stack.b, len);
	if (len > 5)
		sort_big(&stack.a, &stack.b);
	exit_prog(&stack.a, &stack.b, s);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

// The function `normalize` takes in command line arguments and splits them
// into individual words, then joins them into a single array.
char	**join_array(char **dest, char **src)
{
	char	**new;
	int		i;
	int		j;

	if (!dest || !src)
		return (NULL);
	new = ft_calloc(array_len(dest) + array_len(src) + 1, sizeof (char *));
	if (!new)
		return (NULL);
	i = 0;
	while (dest[i])
	{
		new[i] = ft_strdup(dest[i]);
		i++;
	}
	j = i;
	i = 0;
	while (src[i])
		new[j++] = ft_strdup(src[i++]);
	free_str(dest);
	free_str(src);
	return (new);
}

char	**normalize(int ac, char **av)
{
	int		i;
	int		j;
	char	**new;
	char	**src;

	i = 1;
	j = 0;
	src = NULL;
	new = ft_calloc(1, sizeof (char *));
	while (i < ac)
	{
		src = ft_split(av[i], ' ');
		if (src)
			new = join_array(new, src);
		i++;
	}
	return (new);
}

int	main(int ac, char	**av)
{
	char	**values;

	if (ac <= 1)
		exit(0);
	values = normalize(ac, av);
	if (!values)
	{
		free_str(values);
		exit(0);
	}
	if (checkers(values) == 0)
	{
		ft_printf("Error!!\n");
		free_str(values);
		exit(0);
	}
	else
		push_swap(values);
}
