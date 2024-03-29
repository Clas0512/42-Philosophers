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
