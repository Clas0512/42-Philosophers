#include "philo.h"

void	ft_write(int mod, t_philo *phi, char *str, t_time time)
{

	if (mod == 1)
	{
		pthread_mutex_lock(&phi->dth);
		printf("%llu - I'm thread %d and i have taken my %s fork\n", time, phi->id + 1, str);
		pthread_mutex_unlock(&phi->dth);
	}
	else 
	{
		pthread_mutex_lock(&phi->dth);
		printf("%llu - I'm thread %d and i'm %s\n", time, phi->id + 1, str);
		pthread_mutex_unlock(&phi->dth);
	}
}
//pthread_mutex_lock(&phi->dth);
//pthread_mutex_unlock(&phi->dth);

void	last_meal(t_philo *phi)
{
	phi->last_meal_time = ft_get_time();
}

void    ft_eat(t_philo *phi)
{
	pthread_mutex_lock(&phi->forks[phi->id]);
	ft_write(1, phi, "left", ft_get_time() - phi->start_time);
	pthread_mutex_lock(&phi->forks[(phi->id + 1) % (phi->number_of_ph)]);
	ft_write(1, phi, "right", ft_get_time() - phi->start_time);
	ft_write(2, phi, "eating", ft_get_time() - phi->start_time);
	if (phi->size_of_stomach >= 0)
		phi->size_of_stomach--;
	ft_sleep_time(phi->time_to_eat);
	if (phi->time_to_die < (ft_get_time() - phi->last_meal_time))
		phi->is_died = 1;
	pthread_mutex_lock(&phi->dth);
	last_meal(phi);
	pthread_mutex_unlock(&phi->dth);
	pthread_mutex_unlock(&phi->forks[phi->id]);
	pthread_mutex_unlock(&phi->forks[(phi->id + 1) % (phi->number_of_ph)]);
	ft_write(2, phi, "sleeping", ft_get_time() - phi->start_time);
	ft_sleep_time(phi->time_to_sleep);
	ft_write(2, phi, "thinking", ft_get_time() - phi->start_time);
}