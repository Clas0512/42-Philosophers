#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef unsigned long long t_time;

typedef struct s_philo
{
	bool			size_of_stomachs;
	t_time			start_time;
	t_time			last_meal_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dth;
	pthread_t		thrd;
	int				is_died;
	int				id;
	int				number_of_ph;
	int 			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				size_of_stomach;
}	t_philo;

void	ft_eat(t_philo *phi);
t_time	ft_get_time(void);
void	ft_create_threads(pthread_mutex_t *forks, t_philo *phi);
void	ft_sleep_time(t_philo *phi, int time);
void	ft_setting_philos(pthread_mutex_t *forks, pthread_mutex_t *dth, t_philo *phi, char **av, int ac);
void	*ft_manage(void *rtn);
void	ft_frexit();
void	ft_mutex_init(t_philo *phi);
void	ft_write(int mod, t_philo *phi, char *str, t_time time);
//int	ft_blackhole(t_philo *phi);
int		ft_death_check(t_philo *phi, t_time time);
int		ft_atoi(char *str);
int		ft_stomach_check(t_philo *phi);

#endif