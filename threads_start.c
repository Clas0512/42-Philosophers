/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:32:22 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 23:29:23 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(pthread_mutex_t *forks, t_philo *phi)
{
	int		i;
	t_time	time;

	i = 0;
	forks = phi->forks;
	while (i < phi->number_of_ph)
	{
		pthread_create(&phi[i].thrd, NULL, &ft_manage, &phi[i]);
		usleep(100);
		i++;
	}
	while (1)
	{
		pthread_mutex_lock(phi->dth);
		time = ft_get_time() - phi->start_time;
		pthread_mutex_unlock(phi->dth);
		i = ft_death_check(phi, time);
		if (i != -1)
			break ;
		else if (phi->stomach_limit == true && ft_stomach_check(phi, time))
			break ;
	}
}
