/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliman <nliman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:03:29 by nliman            #+#    #+#             */
/*   Updated: 2022/12/10 19:15:38 by nliman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_digit(av[i]) == 0 || ft_atoi(av[i]) <= 0)
		{
			printf("you entered invalid argument!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*lock;

	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
		{
			philo = malloc(sizeof(*philo) * ft_atoi(av[1]));
			fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
			lock = malloc(sizeof(pthread_mutex_t));
			if (!philo || !fork || !lock)
				return (2);
			init_philos(philo, av, ac);
			init_mutex(philo, fork, lock);
			create_threads(philo);
			ft_free(philo, fork, lock);
		}
	}
	return (0);
}
