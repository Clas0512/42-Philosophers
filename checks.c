/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:57:41 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 13:48:20 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death_check(t_philo  *phi)
{
	int	i;

	pthread_mutex_lock(phi->dth);
	i = 0;
	while (i < phi->number_of_ph)
	{
		if (phi[i].is_died == 1)
		{
			//usleep(25);
			return (i);
		}
		i++;
	}
	pthread_mutex_unlock(phi->dth);
	return (-1);
}

int ft_stomach_check(t_philo *phi)
{
	int	i;

	pthread_mutex_lock(phi->dth);
	i = 0;
	while (i < phi->number_of_ph)
	{
		//printf("philo %d  --  size of stomach : %d\n", phi->id, phi->size_of_stomach);
		if (phi[i].size_of_stomach > 0) // burda bi sıkntı var
			return (0);
		i++;
	}
	//printf("philo %d  --  size of stomach : %d\n", phi->id, phi->size_of_stomach);
	pthread_mutex_unlock(phi->dth);
	return (1);
}