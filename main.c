/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:31:32 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 13:04:09 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int ac, char **args)
{
	int	i;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		while (i < ac)
		{
			if (!is_digit(args[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ft_check_args(ac, av))
	{
		pthread_mutex_t	*forks;
		t_philo			*phi;
		pthread_mutex_t	*dth;

		phi = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		forks = malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
		dth = malloc(sizeof(pthread_mutex_t));
		ft_init_philos(forks, dth, phi, av, ac);
		ft_mutex_init(phi);
		ft_create_threads(forks, phi);
	}
	return (0);
}
