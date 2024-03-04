/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:56:07 by mde-avel          #+#    #+#             */
/*   Updated: 2024/03/04 19:08:32 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> //malloc & free
# include <string.h> //memset
# include <stdio.h> //printf
# include <unistd.h> //write & usleep
# include <sys/time.h> //gettimeofday
# include <limits.h> // Max_int
# include <pthread.h> //pthread_...

# define RED	"\033[1;31m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define RESET	"\033[0m"

typedef struct s_philo
{
	pthread_t		thread;
	int 			i;
	int				n_times_ate;
	int				left_f;
	int				rigth_f;
	long int		t_last_meal;
	int				is_dead;
	pthread_mutex_t	mutex_fork;
	int				on_hand;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_n_meals;
	long int		start_time;
	pthread_mutex_t	print;
	int				dead;
	pthread_mutex_t	mutex_die;
	t_philo			*philo;
}	t_data;

//eat.c
int			taking_fork(t_philo *philo, int i);
void		putting_forks(int i);
int			philo_eats(t_philo *philo);

//routine.c
void		print_logs(t_philo *philo, char *str, char *color, int check);
int			sleep_action(long long action, t_philo *philo);
int			check_dead(t_philo *philos);
void		*routine(void *arg);

//utils.c
t_data		*info(void);
long int	timestamp(void);
long int	time_diff(long int start, long int last_action);
int			ft_atoi(const char *str);

#endif