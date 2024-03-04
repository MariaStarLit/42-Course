/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:51:38 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/25 16:57:57 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	token_message(char token)
{
	write(2, "MiniShell: syntax error near unexpected token", 45);
	write(2, " `", 2);
	write(2, &token, 1);
	write(2, "\'\n", 2);
	return (1);
}

void	heredoc_eof(char *limiter)
{
	ft_putstr_fd("Minishell: warning: here-document delimited ", STDERR_FILENO);
	ft_putstr_fd("by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(limiter, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}
