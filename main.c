/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:31:32 by anargul           #+#    #+#             */
/*   Updated: 2023/05/04 23:48:11 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	*forks;
	t_philo			*phi;
	pthread_mutex_t	*dth;

	if (ft_check_args(ac, av))
	{
		phi = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		forks = malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
		dth = malloc(sizeof(pthread_mutex_t));
		ft_init_philos(phi, av, ac);
		ft_mutex_init(phi, dth, forks);
		ft_create_threads(forks, phi);
	}
	else
		printf("%sCheck Args\n", AC_RED);
	return (0);
}
