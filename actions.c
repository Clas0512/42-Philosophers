/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:20:11 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 23:20:11 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(int mod, t_philo *phi, char *str, t_time time)
{
	pthread_mutex_lock(phi->dth);
	if (mod == 1)
		printf("%llu - I'm thread %d and i have taken my %s fork\n", time,
			phi->id + 1, str);
	else
		printf("%llu - I'm thread %d and i'm %s\n", time, phi->id + 1, str);
	pthread_mutex_unlock(phi->dth);
}

void	last_meal(t_philo *phi)
{
	pthread_mutex_lock(phi->dth);
	phi->last_meal_time = ft_get_time();
	pthread_mutex_unlock(phi->dth);
}

void	one_philo_check(t_philo *phi)
{
	if (phi->number_of_ph == 1)
	{
		ft_sleep_time(phi, phi->time_to_die);
		phi->is_died = 1;
	}
}

void	double_check(t_philo *phi, int mod)
{
	pthread_mutex_lock(phi->dth);
	if (mod == 1)
	{
		if (phi->stomach_limit == true && phi->size_of_stomach >= 0)
			phi->size_of_stomach--;
	}
	else
	{
		if (phi->time_to_die < (int)(ft_get_time() - phi->last_meal_time))
			phi->is_died = 1;
	}
	pthread_mutex_unlock(phi->dth);
}

void	*ft_manage(void *rtn)
{
	t_philo	*phi;

	phi = (t_philo *)rtn;
	while (1)
	{
		pthread_mutex_lock(&phi->forks[phi->id]);
		ft_write(1, phi, "left", ft_get_time() - phi->start_time);
		one_philo_check(phi);
		pthread_mutex_lock(&phi->forks[(phi->id + 1) % (phi->number_of_ph)]);
		ft_write(1, phi, "right", ft_get_time() - phi->start_time);
		ft_write(2, phi, "eating", ft_get_time() - phi->start_time);
		double_check(phi, 1);
		ft_sleep_time(phi, phi->time_to_eat);
		double_check(phi, 2);
		last_meal(phi);
		pthread_mutex_unlock(&phi->forks[phi->id]);
		pthread_mutex_unlock(&phi->forks[(phi->id + 1) % (phi->number_of_ph)]);
		ft_write(2, phi, "sleeping", ft_get_time() - phi->start_time);
		ft_sleep_time(phi, phi->time_to_sleep);
		ft_write(2, phi, "thinking", ft_get_time() - phi->start_time);
	}
}
