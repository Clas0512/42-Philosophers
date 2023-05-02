/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:31:04 by anargul           #+#    #+#             */
/*   Updated: 2023/05/02 19:46:13 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	rtrn;

	rtrn = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		rtrn = rtrn * 10 + str[i] - '0';
		i++;
	}
	rtrn *= sign;
	return (rtrn);
}

t_time	ft_get_time(void)
{
	struct timeval		timevl;
	t_time				time;

	gettimeofday(&timevl, NULL);
	time = timevl.tv_sec * 1000 + timevl.tv_usec / 1000;
	return (time);
}

void	ft_sleep_time(t_philo *phi, int ttime)
{
	pthread_mutex_lock(&phi->dth);
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < (t_time)ttime)
		usleep(100);
	pthread_mutex_unlock(&phi->dth);
}

int	ft_death_check(t_philo  *phi, t_time time)
{
	int	i;
	//t_time time = ft_get_time();

	pthread_mutex_lock(&phi->dth);
	i = 0;
	while (i < phi->number_of_ph)
	{
		//if ((t_time)phi[i].time_to_die < (time - phi[i].last_meal_time))
		//	phi[i].is_died = 1;
		if (phi[i].is_died == 1)
		{
			//usleep(25);
			return (i);
		}
		i++;
	}
	pthread_mutex_unlock(&phi->dth);
	return (-1);
}

int ft_stomach_check(t_philo *phi)
{
	int	i;

	pthread_mutex_lock(&phi->dth);
	i = 0;
	//if (phi[0].size_of_stomach == 0 && phi[phi->number_of_ph - 1].size_of_stomach == 0)
	//	return (-1);
	while (i < phi->number_of_ph)
	{
		if (phi[i].size_of_stomachs == false)
			return (0);
		i++;
	}
	return (-1);
}