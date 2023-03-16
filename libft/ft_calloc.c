/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:11:17 by mde-avel          #+#    #+#             */
/*   Updated: 2022/11/24 14:57:39 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It allocates memory for an array. Then the memory is set to zero.
 * 
 * @param nitems The number of elements to be allocated.
 * @param size The size of the memory block, in bytes.
 * 
 * @return A pointer to the allocated memory.
 */

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ma;

	ma = malloc(nitems * size);
	if (!ma)
	{
		return (NULL);
	}
	ft_bzero(ma, nitems * size);
	return (ma);
}

/*int	main(void)
{
	int	i;
	int	n;
	int	*a;

	printf("Number of elements to be entered: ");
	scanf("%d", &n);

	a = (int *)calloc(n, sizeof(int));
	printf("Enter %d numbers:\n",n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("The numbers entered are: ");
	for(i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	return (0);
}*/
