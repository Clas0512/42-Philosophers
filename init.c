/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:55:01 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 23:25:44 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philos(t_philo *phi, char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		if (ac == 6)
		{
			phi[i].stomach_limit = true;
			phi[i].size_of_stomach = ft_atoi(av[5]);
		}
		else
			phi[i].stomach_limit = false;
		phi[i].start_time = ft_get_time();
		phi[i].last_meal_time = phi[i].start_time;
		phi[i].number_of_ph = ft_atoi(av[1]);
		phi[i].time_to_die = ft_atoi(av[2]);
		phi[i].time_to_eat = ft_atoi(av[3]);
		phi[i].time_to_sleep = ft_atoi(av[4]);
		phi[i].is_died = 0;
		phi[i].id = i;
		i++;
	}
}

void	ft_mutex_init(t_philo *phi, pthread_mutex_t *dth,
			pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < phi->number_of_ph)
	{
		phi[i].forks = forks;
		pthread_mutex_init(&phi->forks[i], NULL);
		phi[i].dth = dth;
		i++;
	}
	pthread_mutex_init(phi->dth, NULL);
}
