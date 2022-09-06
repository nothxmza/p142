#include "philo.h"

t_info	*info_init(void)
{
	static t_info	*info;

	if (!info)
	{
		info = malloc(sizeof(t_info));
		memset(info, 0, sizeof(t_info));
	}
	if (!info)
		return (0);
	return (info);
}

void	philo_init(void)
{
	 t_info	*p;

	p = info_init();
	p->philosopher = (t_philo *)malloc(sizeof(t_philo) * p->nop);
	memset(p->philosopher, 0, sizeof(t_info));
	if (!p->philosopher)
		ft_exit("Erreur de malloc du philo");
	p->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p->nop);
	if(!p->m_forks)
		ft_exit("Erreur de malloc des forks");
}
