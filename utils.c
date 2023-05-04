/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:31:04 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 13:06:27 by anargul          ###   ########.fr       */
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

void	ft_sleep_time(int ttime)
{
	t_time	time;

	//pthread_mutex_lock(phi->dth);
	time = ft_get_time();
	while (ft_get_time() - time < (t_time)ttime)
		usleep(100);
	//pthread_mutex_unlock(phi->dth);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (('9' <= str[i] && str[i] <= '0'))
			return (0);
		i++;	
	}
	return (1);
}
