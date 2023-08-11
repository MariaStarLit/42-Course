/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:52:42 by mde-avel          #+#    #+#             */
/*   Updated: 2023/08/10 17:30:41 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	t_lista	*a;
	t_lista	*b;
}	t_stack;

//push_swap.c
//void	print_lst(t_lista **lst, char c);
void	push_swap(char **av);
int		array_len(char **array);
char	**join_array(char **dest, char **src);
char	**normalize(int ac, char **av);
//int 	main

//utlis.c
void	create_lst_a(char *s, t_lista **a);
void	free_lst(t_lista **lst);
void	free_str(char **s);
void	exit_prog(t_lista **a, t_lista **b, char **s);

//checks.c
int		checkers(char **s);
int		check_if_num(char *s);
int		check_repeat_num(char **av, int n);
int		check_if_organized(t_lista **a);

//sort_small.c
void	sort_small(t_lista **a, t_lista **b, int ac);
void	sort_four(t_lista **a, t_lista **b);
void	find_min_nbr(t_lista **a, t_lista *last);
void	sort_five(t_lista **a, t_lista **b);

//sort_big.c
void	simpler_num(t_lista **a, int len);
void	radix(t_lista **a, t_lista **b, int n_bits, int len);
void	sort_big(t_lista **a, t_lista **b);

//moves_1.c
void	sa(t_lista **a, int flag);
void	sb(t_lista **b, int flag);
void	ss(t_lista **a, t_lista **b);
void	pa(t_lista **a, t_lista **b);
void	pb(t_lista **a, t_lista **b);

//moves_2.c
void	ra(t_lista **a, int flag);
void	rb(t_lista **b, int flag);
void	rr(t_lista **a, t_lista **b);

//moves_3.c
void	rra(t_lista **a, int flag);
void	rrb(t_lista **b, int flag);
void	rrr(t_lista **a, t_lista **b);

#endif