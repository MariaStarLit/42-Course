/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:54:11 by mde-avel          #+#    #+#             */
/*   Updated: 2024/02/05 15:15:16 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if (ft_atoi(av[i]) <= 0)
			{
				printf("Error!\nArgumentes must be a positive integer.\n");
				return (0);
			}
			i++;
		}
		return (1);
	}
	else
		printf("Error!\nInvalid number of Arguments.\n");
	return (-1);
}

int	get_args(int ac, char **av)
{
	if (check_args(ac, av) < 1)
		return (0);
	info()->n_philo = ft_atoi(av[1]);
	info()->time_die = ft_atoi(av[2]);
	info()->time_eat = ft_atoi(av[3]);
	info()->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info()->max_n_meals = ft_atoi(av[5]);
	else
		info()->max_n_meals = INT_MAX;
	return (1);
}

void	init_vars(int i)
{
	info()->dead = 0;
	info()->philo = malloc(sizeof(t_philo) * info()->n_philo);
	if (!info()->philo)
		return ;
	pthread_mutex_init(&info()->print, NULL);
	pthread_mutex_init(&info()->mutex_die, NULL);
	while (i < info()->n_philo)
	{
		pthread_mutex_init(&info()->philo[i].mutex_fork, NULL);
		info()->philo[i].i = i;
		info()->philo[i].on_hand = 0;
		i++;
	}
	info()->start_time = timestamp();
	i = -1;
	while (++i < info()->n_philo)
		pthread_create(&info()->philo[i].thread, NULL, &routine, \
			&info()->philo[i]);
	while (--i >= 0)
		pthread_join(info()->philo[i].thread, NULL);
}

void	exit_program(void)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info()->print);
	pthread_mutex_destroy(&info()->mutex_die);
	while (i < info()->n_philo)
	{
		pthread_mutex_destroy(&info()->philo[i].mutex_fork);
		i++;
	}
	free(info()->philo);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (get_args(ac, av) == 0)
		return (0);
	init_vars(i);
	exit_program();
}
