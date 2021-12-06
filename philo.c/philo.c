/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:24:54 by cdelaine          #+#    #+#             */
/*   Updated: 2021/12/06 19:54:02 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *check_dead(void *philo_r)
{
	t_philo *philo;

	philo = philo_r;
	while(1)
	{
		pthread_mutex_lock(&philo->action);
		if (!(philo->eat_now) && get_time() > philo->time_limit)
		{
			print_message(5, philo);
			pthread_mutex_unlock(&philo->action);
			pthread_mutex_unlock(&philo->info->check_dead);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->action);
		usleep(1000);
	}
}

void *life(void *philo_r)
{
	t_philo *philo;
	pthread_t thread_id;

	philo = philo_r;
	philo->eat_start = get_time();
	philo->time_limit  = philo->eat_start + philo->info->time_to_die;
	pthread_create(&thread_id, NULL, &check_dead, philo_r);
	pthread_detach(thread_id);
	while(1)
	{
		do_eat(philo);
		do_sleep(philo);
		print_message(4, philo);
	}
}

void *how_meals(void *info_r)
{
	int i;
	int eat;
	t_info *info;

	eat = 0;
	info = info_r;
	while (eat < info->how_much_eat)
	{
		i = 0;
		while (i < info->philo_num)
			pthread_mutex_lock(&info->philo[i++].eating);
		eat++;
	}
	print_message(6, &info->philo[0]);
	pthread_mutex_unlock(&info->check_dead);
}

int start_pthread(t_info *info)
{
	int i;
	pthread_t thread_id;
	t_philo *philo;

	i = 0;
	info->start_time = get_time();
	if (info->how_much_eat > 0)
	{
		if (pthread_create(&thread_id, NULL, &how_meals, info))
			return (1);
		pthread_detach(thread_id);
	}
	while (i < info->philo_num)
	{
		philo = &info->philo[i];
		if (pthread_create(&thread_id, NULL, &life, info))
			return (1);
		pthread_detach(thread_id);
		usleep(100);
		i++;
	}
	return (0);
}

void clean_mem(t_info *info)
{
	int i;

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

int philo_init(t_info *info)
{
	int i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->philo_num);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!(info->forks) || !(info->philo))
		return (1);
	while (i < info->philo_num)
	{
		info->philo[i].num = i;
		info->philo[i].left = i;
		info->philo[i].right = (i + 1) % info->philo_num;
		info->philo[i].info = info;
		info->philo[i].eat_now = 0;
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philo[i].action, NULL);
		pthread_mutex_init(&info->philo[i].eating, NULL);
		pthread_mutex_lock(&info->philo[i].eating);
		i++;
	}
	pthread_mutex_init(&info->message, NULL);
	pthread_mutex_init(&info->check_dead, NULL);
	pthread_mutex_lock(&info->check_dead);
	return (0);
}

int check_argum(int argc, char **argv, t_info *info)
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

int main(int argc, char **argv)
{
	t_info info;

	if (check_argum(argc, argv, info))
		return (printf("Error\n"));
	if (philo_init())
	{
		clean_mem();
		return (printf("Error\n"));
	}
	if (start_pthread())
	{
		clean_mem();
		return (printf("Error\n"));
	}
	pthread_mutex_lock();
	pthread_mutex_unlock();
	clean_mem();
	return (0);
}
