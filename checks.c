/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:57:41 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 23:35:17 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death_check(t_philo *phi, t_time time)
{
	int	i;

	pthread_mutex_lock(phi->dth);
	i = 0;
	while (i < phi->number_of_ph)
	{
		if (phi[i].is_died == 1)
		{
			usleep(100);
			printf("%s%llu - Philosopher %d is died\n", AC_RED, time, i + 1);
			return (i);
		}
		i++;
	}
	pthread_mutex_unlock(phi->dth);
	return (-1);
}

int	ft_stomach_check(t_philo *phi, t_time time)
{
	int	i;

	pthread_mutex_lock(phi->dth);
	i = 0;
	while (i < phi->number_of_ph)
	{
		if (phi[i].size_of_stomach > 0)
		{
			pthread_mutex_unlock(phi->dth);
			return (0);
		}
		i++;
	}
	printf("%s%llu - Philosophers stomach are full\n", AC_GRY, time);
	return (1);
}
