/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:22:19 by mde-avel          #+#    #+#             */
/*   Updated: 2024/02/05 16:45:19 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_logs(t_philo *philo, char *str, char *color, int check)
{
	long int	time;

	pthread_mutex_lock(&info()->print);
	if (!check || check_dead(philo) == 0)
	{
		time = timestamp() - info()->start_time;
		printf("%li ms %s%i %s\n%s", time, color, philo->i + 1, str, RESET);
	}
	pthread_mutex_unlock(&info()->print);
}

int	sleep_action(long long action, t_philo *philo)
{
	long long	begin;
	long long	time_passed;

	begin = timestamp();
	time_passed = 0;
	while (time_passed < action)
	{
		if (check_dead(philo))
			return (1);
		usleep(100);
		time_passed = time_diff(begin, timestamp());
		if (time_passed >= action)
			return (0);
	}
	return (0);
}

int	check_dead(t_philo *philo)
{
	long int	curr_time;
	long int	t_since_l_meal;

	curr_time = timestamp() - info()->start_time;
	t_since_l_meal = time_diff(philo->t_last_meal, curr_time);
	pthread_mutex_lock(&info()->mutex_die);
	if (info()->dead > 0)
	{
		pthread_mutex_unlock(&info()->mutex_die);
		return (2);
	}
	if (t_since_l_meal >= info()->time_die)
	{
		info()->dead = 1;
		pthread_mutex_unlock(&info()->mutex_die);
		print_logs(philo, "died", RED, 0);
		return (1);
	}
	pthread_mutex_unlock(&info()->mutex_die);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->t_last_meal = 0;
	philo->n_times_ate = 0;
	if (!(philo->i % 2))
		usleep(500);
	while (check_dead(philo) == 0)
	{
		if (philo_eats(philo) == 1)
			break ;
		if (philo->n_times_ate == info()->max_n_meals)
			return (NULL);
		print_logs(philo, "is sleeping", BLUE, 1);
		sleep_action(info()->time_sleep, philo);
		if (info()->dead > 0)
			break ;
		print_logs(philo, "is thinking", PURPLE, 1);
		usleep(100);
	}
	return (NULL);
}
