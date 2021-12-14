/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:25:23 by cdelaine          #+#    #+#             */
/*   Updated: 2021/12/14 14:34:15 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

struct	s_info;

typedef struct s_philo
{
	int				num;
	int				left;
	int				right;
	unsigned int	eat_start;
	struct s_info	*info;
	int				eat_now;
	unsigned int	time_limit;
	pthread_mutex_t	actions;
	pthread_mutex_t	eating;

}				t_philo;

typedef struct s_info
{
	int				philo_num;
	int				time_to_eat;
	unsigned int	time_to_die;
	int				time_to_sleep;
	int				how_much_eat;
	t_philo			*philo;
	unsigned int	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	pthread_mutex_t	check_dead;

}					t_info;

int				ft_atoi(const char *nptr);
unsigned int	get_time(void);
int				philo_init(t_info *info);
int				check_argum(int argc, char **argv, t_info *info);
void			clean_mem(t_info *info);
int				start_pthread(t_info *info);
void			*how_meals(void *info_r);
void			*life(void *philo_r);
void			*check_dead(void *philo_r);
void			take_forks(t_philo *philo);
void			do_eat(t_philo *philo);
void			do_sleep(t_philo *philo);
int				print_message(int flag, t_philo *philo);
void			my_usleep(long time);

#endif
