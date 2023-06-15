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

int	ft_check_args(int ac, char **args)
{
	int	i;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		while (i < ac)
		{
			if (!is_digit(args[i]) || *args[i] == '\0')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
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
