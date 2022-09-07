#include "philo.h"

void	create_philo(t_info *p)
{
	int i;

	i = -1;
	p->start_time = get_time();
	while(++i < p->nop)
	{
		p->philosopher[i].id = i;
		p->philosopher[i].info = p;
		if (pthread_create(&(p->philosopher[i].thread), NULL, routine_philo,
				&p->philosopher[i]))
		{
			ft_exit("no\n");
		}
		p->philosopher[i].last_meal = p->start_time;
	}
	i = -1;
	while(++i < p->nop)
		pthread_join(p->philosopher[i].thread, NULL);
	destroys(p, p->philosopher);
}

void destroys(t_info *info, t_philo *m)
{
	int i;

	i = -1;
	while(++i < info->nop)
		pthread_mutex_destroy(&(info->m_forks[i]));
	pthread_mutex_destroy(&(info->m_print));
}
