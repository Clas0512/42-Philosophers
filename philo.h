#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef unsigned long long	t_time;
# define AC_RED "\x1b[41;5;197m"
# define AC_GRN "\x1b[42;5;10m"
# define AC_GRY "\x1b[47;5;231m"

typedef struct s_philo
{
	bool			stomach_limit;
	t_time			start_time;
	t_time			last_meal_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*dth;
	pthread_t		thrd;
	int				is_died;
	int				id;
	int				number_of_ph;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				size_of_stomach;
}					t_philo;

t_time	ft_get_time(void);
void	ft_create_threads(pthread_mutex_t *forks, t_philo *phi);
void	ft_sleep_time(t_philo *phi, int time);
void	ft_init_philos(t_philo *phi, char **av, int ac);
void	ft_mutex_init(t_philo *phi, pthread_mutex_t *dth,
			pthread_mutex_t *forks);
void	*ft_manage(void *rtn);
void	ft_write(int mod, t_philo *phi, char *str, t_time time);
void	one_philo_check(t_philo *phi);
void	double_check(t_philo *phi, int mod);
int		is_digit(char *str);
int		ft_atoi(char *str);
int		ft_death_check(t_philo *phi, t_time time);
int		ft_stomach_check(t_philo *phi, t_time time);
int		ft_check_args(int ac, char **args);

#endif