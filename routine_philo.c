#include "philo.h"

void eat(t_philo *p)
{
	pthread_mutex_lock(&(p->info->m_forks[p->id]));
	print_wMutex(p, "has taken a fork");
	pthread_mutex_lock(&(p->info->m_forks[p->id + 1]));
	print_wMutex(p, "has taken a fork");
	print_wMutex(p, "is eating");
	p->meal++;
	p->last_meal = get_time();
	usleep(p->info->tte * 1000);
	pthread_mutex_unlock(&(p->info->m_forks[p->id]));
	pthread_mutex_unlock(&(p->info->m_forks[p->id + 1]));
}

void	*routine_philo(void *p)
{
	t_philo *philo;
	
	philo = (t_philo *)p;
	if(philo->info->nop == 1)
	{
		pthread_mutex_lock(&(philo->info->m_forks[philo->id]));
		print_wMutex(philo,"has taken a fork");
		pthread_mutex_unlock(&(philo->info->m_forks[philo->id]));
		print_wMutex(philo,"DIE");
		philo->info->status = 1;
	}
	if(philo->id % 2)
		usleep(1000);
	while(philo->info->status != 1)
	{
		eat(philo);
		print_wMutex(philo, "is sleeping");
		usleep(philo->info->tts * 1000);
		print_wMutex(philo, "is thinking");
	}
	return(0);
}