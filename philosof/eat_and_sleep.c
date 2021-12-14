/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_and_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:29:25 by cdelaine          #+#    #+#             */
/*   Updated: 2021/12/14 14:40:42 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->left]);
	print_message(1, philo);
	pthread_mutex_lock(&philo->info->forks[philo->right]);
	print_message(1, philo);
	pthread_mutex_lock(&philo->actions);
	philo->eat_now = 1;
	philo->eat_start = get_time();
	philo->time_limit = philo->eat_start + philo->info->time_to_die;
	print_message(2, philo);
	my_usleep(philo->info->time_to_eat);
	philo->eat_now = 0;
	pthread_mutex_unlock(&philo->actions);
	pthread_mutex_unlock(&philo->eating);
}

void	do_sleep(t_philo *philo)
{
	print_message(3, philo);
	pthread_mutex_unlock(&philo->info->forks[philo->left]);
	pthread_mutex_unlock(&philo->info->forks[philo->right]);
	my_usleep(philo->info->time_to_sleep);
}

void	my_usleep(long time)
{
	long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(100);
}
