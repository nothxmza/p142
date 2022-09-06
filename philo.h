#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct s_info 		t_info;

typedef struct s_philo
{
	int			id;
}			t_philo;

typedef struct s_info
{
	int			nop;
	int			ttd;
	int			tte;
	int			tts;
	int			nte;
	t_philo		*philosopher;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_print;
}			t_info;

//UTILS
int         ft_atoi(const char *str);
int	        ft_isalnum(int c);
void ft_exit(char *str);

//INIT
void		philo_init(void);
t_info		*info_init(void);
//PARSING
void        ft_check_nbr(char **argv, t_info *philo);
void	    ft_check_num(char	**argv);
void	    ft_check(int argc, char **argv, t_info *philo);

#endif