#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>


typedef struct s_info 		t_info;

typedef struct s_philo
{
	pthread_t 		thread;
	int				id;
	int				meal;
	long long 		last_meal;
	t_info			*info;
}					t_philo;

typedef struct s_info
{
	int			nop;
	int			ttd;
	int			tte;
	int			tts;
	int			nte;
	int			status;
	long long	start_time;
	t_philo		*philosopher;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_print;
}			t_info;

//UTILS
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
void		ft_exit(char *str);
void 		print_wMutex(t_philo *p, int id, char *str);
long long	get_time(void);

//INIT
void		philo_init(void);
t_info		*info_init(void);
void		init_mutex(t_info *p);

//PARSING
void		ft_check_nbr(char **argv, t_info *philo);
void		ft_check_num(char	**argv);
void		ft_check(int argc, char **argv, t_info *philo);

//ROUTINE
void	*routine_philo(void *p);
void eat(t_philo *p);

//CREATE DESTROY
void	create_philo(t_info *p);
void destroys(t_info *info, t_philo *m);

#endif