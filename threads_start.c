/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:32:22 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 13:47:58 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(pthread_mutex_t *forks, t_philo *phi)
{
	int	i;
	forks = phi->forks;
	t_time time;

	i = 0;
	while (i < phi->number_of_ph)
	{
		pthread_create(&phi[i].thrd, NULL, &ft_manage, &phi[i]);
		usleep(150);
		i++;
	}
	while (1)
	{
		pthread_mutex_lock(phi->dth);
		time = ft_get_time() - phi->start_time;
		pthread_mutex_unlock(phi->dth);
		i = ft_death_check(phi);
		if (i != -1)
		{
			usleep(100);
			printf("%s%llu - Philosopher %d is died\n", AC_RED, time, i + 1);
			break ;
		}
		if (ft_stomach_check(phi))
		{
			printf("%s%llu - Philosophers stomach are full\n", AC_GRY, time);
			break ;
		}
	}
}
