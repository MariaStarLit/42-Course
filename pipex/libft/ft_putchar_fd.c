/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:42:28 by mde-avel          #+#    #+#             */
/*   Updated: 2023/03/08 14:57:15 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Write the character c to the file descriptor fd.
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
