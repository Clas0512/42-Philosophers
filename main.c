/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:31:32 by anargul           #+#    #+#             */
/*   Updated: 2023/05/02 19:56:14 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_death_mutex(int c, t_philo *phi, pthread_mutex_t *dth)
{
	int i;

	i = 0;
	while (i < phi->number_of_ph)
	{
		phi[i].size_of_stomachs = false;
		phi[i].dth = *dth;
		i++;
	}
}

void	ft_setting_philos(pthread_mutex_t *forks, pthread_mutex_t *dth, t_philo *phi, char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		phi[i].start_time = ft_get_time();
		phi[i].last_meal_time = phi[i].start_time;
		phi[i].is_died = 0;
		phi[i].id = i;
		phi[i].number_of_ph = ft_atoi(av[1]);
		//if (phi[i].number_of_ph < 2)
		//{
		//	phi->is_died = 1;	
		//}
		phi[i].time_to_die = ft_atoi(av[2]);
		phi[i].time_to_eat = ft_atoi(av[3]);
		phi[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			phi[i].size_of_stomach = ft_atoi(av[5]);
		else
			phi[i].size_of_stomach = -1;
		i++;
	}
	ft_set_death_mutex(i, phi, dth);
	i = 0;
	while (i < phi->number_of_ph)
	{
		phi[i].forks = forks;
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
}

int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		pthread_mutex_t	*forks;
		t_philo			*phi;
		pthread_mutex_t	dth;

		phi = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		forks = malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
		ft_setting_philos(forks, &dth, phi, av, ac);
		ft_mutex_init(phi);
		ft_create_threads(forks, phi);
	}
	return (0);
}
