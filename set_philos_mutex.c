/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliman <nliman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:03:01 by nliman            #+#    #+#             */
/*   Updated: 2022/12/10 19:16:28 by nliman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo *philo, char **av, int ac)
{
	int	*is_dead;
	int	i;

	i = 0;
	is_dead = malloc(sizeof(int));
	*is_dead = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].id = i;
		philo[i].die_time = ft_atoi(av[2]);
		philo[i].eat_time = ft_atoi(av[3]);
		philo[i].sleep_time = ft_atoi(av[4]);
		if (ac == 6)
			philo[i].goal = ft_atoi(av[5]);
		else
			philo[i].goal = -1;
		philo[i].last_meal = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].eaten = 0;
		philo[i].philo_num = ft_atoi(av[1]);
		philo[i].is_dead = is_dead;
		i++;
	}
	i = 0;
}

void	init_mutex(t_philo *philo, pthread_mutex_t *fork, \
		pthread_mutex_t *lock)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		philo[i].left_fork_mutex = &fork[i];
		philo[i].right_fork_mutex = &fork[(i + 1) % philo->philo_num];
		i++;
	}
	i = 0;
	while (i < philo->philo_num)
	{
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		philo[i].lock = lock;
		i++;
	}
	pthread_mutex_init(philo->lock, NULL);
}

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, &loops_for_philos, &philo[i]);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < philo->philo_num)
		pthread_join(philo[i++].thread, NULL);
	while ((*philo).is_dead == 0)
	{
		ft_philo_check(philo);
	}
}
