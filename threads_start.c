/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:32:22 by anargul           #+#    #+#             */
/*   Updated: 2023/05/02 19:53:55 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//#define AC_RED "\x1b[31m"

void	ft_create_threads(pthread_mutex_t *forks, t_philo *phi)
{
	int	i;
	forks = phi->forks;
	t_time time;

	i = 0;
	while (i < phi->number_of_ph)
	{
		pthread_create(&phi[i].thrd, NULL, &ft_manage, &phi[i]);
		usleep(200);
		i++;
	}
	while (1)
	{
		pthread_mutex_lock(&phi->dth);
		time = ft_get_time() - phi->start_time;
		pthread_mutex_unlock(&phi->dth);
		i = ft_death_check(phi, time);
		if (i != -1)
		{
			usleep(100);
			printf("%llu - Philosopher %d is died\n", time, i + 1);
			break ;
		}
		if (ft_stomach_check(phi) == -1)
		{
			printf("%llu - Philosophers stomach are full\n", time);
			break ;
		}
		pthread_mutex_unlock(&phi->dth);
	}
}

//int	ft_blackhole(t_philo *phi)
//{
//	t_time time;
//	int i;

//	time = ft_get_time() - phi->start_time;
//	//pthread_mutex_lock(&phi->dth);
//	i = ft_death_check(phi);
//	//pthread_mutex_unlock(&phi->dth);
//	if (i != -1)
//	{
//		//ft_sleep_time(100);
//		//usleep(20);
//		printf("%llu - %d Philosopher is died\n", time, i + 1);
//		return (1);
//	}
//	if (ft_stomach_check(phi) == -1)
//	{
//		usleep(20);
//		printf("%llu - Philosophers stomach are full\n", time);
//		return (1);
//	}
//	return (0);
//}

void	*ft_manage(void *rtn)
{
	t_philo *phi = (t_philo *)rtn;

	while (1)
	{
		ft_eat(phi);
		//ft_blackhole(phi);
	}
}
