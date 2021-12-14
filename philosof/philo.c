/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:24:54 by cdelaine          #+#    #+#             */
/*   Updated: 2021/12/14 14:44:22 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argum(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
		return (1);
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->forks = NULL;
	info->philo = NULL;
	if (argc == 6)
	{
		info->how_much_eat = ft_atoi(argv[5]);
		if (info->how_much_eat <= 0)
			return (1);
	}
	else
		info->how_much_eat = 0;
	if (info->philo_num <= 0 || info->time_to_die < 60 || info->time_to_eat \
	<= 0 || info->time_to_sleep < 60)
		return (1);
	return (0);
}

void	clean_mem(t_info *info)
{
	int	i;

	i = 0;
	if (info->philo)
	{
		while (i < info->philo_num)
		{
			pthread_mutex_destroy(&info->philo[i].actions);
			pthread_mutex_destroy(&info->philo[i].eating);
			i++;
		}
		i = 0;
		if (info->forks)
		{
			while (i < info->philo_num)
				pthread_mutex_destroy(&info->forks[i++]);
			free(info->forks);
			info->forks = NULL;
		}
		pthread_mutex_destroy(&info->message);
		pthread_mutex_destroy(&info->check_dead);
		free(info->philo);
		info->philo = NULL;
	}
}

int	print_message(int flag, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->message);
	printf("%u ", get_time() - philo->info->start_time);
	if (flag != 6)
		printf("%d", philo->num + 1);
	if (flag == 1)
		printf(" take a fork\n");
	else if (flag == 2)
		printf(" is eating\n");
	else if (flag == 3)
		printf(" is sleeping\n");
	else if (flag == 4)
		printf(" is thinking\n");
	else if (flag == 5)
	{
		printf(" died\n");
		return (0);
	}
	else if (flag == 6)
	{
		printf("the number of meals is over\n");
		return (0);
	}
	pthread_mutex_unlock(&philo->info->message);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (check_argum(argc, argv, &info))
		return (printf("Error\n"));
	if (philo_init(&info))
	{
		clean_mem(&info);
		return (printf("Error\n"));
	}
	if (start_pthread(&info))
	{
		clean_mem(&info);
		return (printf("Error\n"));
	}
	pthread_mutex_lock(&info.check_dead);
	pthread_mutex_unlock(&info.check_dead);
	clean_mem(&info);
	return (0);
}
