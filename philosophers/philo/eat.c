/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:36:05 by mde-avel          #+#    #+#             */
/*   Updated: 2024/02/05 16:55:44 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	taking_fork(t_philo *philo, int i)
{
	while (check_dead(philo) == 0)
	{
		pthread_mutex_lock(&info()->philo[i].mutex_fork);
		if (info()->philo[i].on_hand == 0)
		{
			info()->philo[i].on_hand = 1;
			pthread_mutex_unlock(&info()->philo[i].mutex_fork);
			return (0);
		}
		else
			pthread_mutex_unlock(&info()->philo[i].mutex_fork);
	}
	return (1);
}

void	putting_forks(int i)
{
	pthread_mutex_lock(&info()->philo[i].mutex_fork);
	info()->philo[i].on_hand = 0;
	pthread_mutex_unlock(&info()->philo[i].mutex_fork);
}

int	philo_eats2(t_philo *philo)
{
	if (philo->i % 2)
	{
		if (taking_fork(philo, philo->left_f) == 1)
			return (1);
		print_logs(philo, "has taken the left fork", YELLOW, 1);
		if (taking_fork(philo, philo->rigth_f) == 1)
			return (1);
		print_logs(philo, "has taken the rigth fork", YELLOW, 1);
	}
	else
	{
		if (taking_fork(philo, philo->rigth_f) == 1)
			return (1);
		print_logs(philo, "has taken the rigth fork", YELLOW, 1);
		if (taking_fork(philo, philo->left_f) == 1)
			return (1);
		print_logs(philo, "has taken the left fork", YELLOW, 1);
	}
	return (0);
}

int	philo_eats(t_philo *philo)
{
	philo->rigth_f = philo->i;
	if (info()->n_philo > 1)
		philo->left_f = philo->i - 1;
	if (philo->i == 0)
		philo->left_f = info()->n_philo - 1;
	if (philo_eats2(philo) == 1)
		return (1);
	print_logs(philo, "is eating", GREEN, 1);
	philo->t_last_meal = timestamp() - info()->start_time;
	philo->n_times_ate++;
	if (sleep_action(info()->time_eat, philo) == 1)
		return (1);
	putting_forks(philo->rigth_f);
	putting_forks(philo->left_f);
	return (0);
}
