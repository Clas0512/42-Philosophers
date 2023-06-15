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
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < (t_time)ttime
		&& (int)(ft_get_time() - time) <= phi->time_to_die)
		usleep(100);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > '9' || str[i] < '0'))
			return (0);
		i++;
	}
	return (1);
}
