/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:55:01 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 13:38:32 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philos(pthread_mutex_t *forks, pthread_mutex_t *dth, t_philo *phi, char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		if (ac == 6)
			phi[i].size_of_stomach = ft_atoi(av[5]);
		else
			phi[i].size_of_stomach = -1;
		phi[i].start_time = ft_get_time();
		phi[i].last_meal_time = phi[i].start_time;
		phi[i].number_of_ph = ft_atoi(av[1]);
		phi[i].time_to_die = ft_atoi(av[2]);
		phi[i].time_to_eat = ft_atoi(av[3]);
		phi[i].time_to_sleep = ft_atoi(av[4]);
		phi[i].forks = forks;
		phi[i].is_died = 0;
		phi[i].id = i;
		phi[i].size_of_stomachs = false;
		phi[i].dth = dth;
		i++;
	}
}

void	ft_mutex_init(t_philo *phi)
{
	int	i;

	i = 0;
	while (i < phi->number_of_ph)
	{
		pthread_mutex_init(&phi->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(phi->dth, NULL);
}
