/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:38:39 by hterras           #+#    #+#             */
/*   Updated: 2022/10/03 13:18:08 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *p)
{
	pthread_mutex_lock(&(p->info->m_forks[p->id]));
	print_wmutex(p, "has taken a fork");
	pthread_mutex_lock(&(p->info->m_forks[p->id + 1]));
	print_wmutex(p, "has taken a fork");
	print_wmutex(p, "is eating");
	p->meal++;
	p->last_meal = get_time();
	usleep2(p->info, p->info->tte);
	pthread_mutex_unlock(&(p->info->m_forks[p->id]));
	pthread_mutex_unlock(&(p->info->m_forks[p->id + 1]));
}

static int	max_eat(t_info *p)
{
	int	i;

	i = -1;
	while (++i < p->nop)
	{
		if (p->philosopher[i].meal > p->nte && p->nte)
				p->all_eat++;
		if (p->all_eat == p->nop)
			p->status = 1;
	}
	return (p->status);
}

void	dead(t_info *p)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < p->nop)
		{
			pthread_mutex_lock(&(p->m_eat));
			if (get_time() - p->philosopher[i].last_meal > p->ttd)
			{
				print_wmutex(p->philosopher, "died");
				p->status = 1;
			}
			pthread_mutex_unlock(&(p->m_eat));
		}
		p->status = max_eat(p);
		if (p->status == 1)
			break ;
	}
}

void	*routine_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->info->nop == 1)
	{
		pthread_mutex_lock(&(philo->info->m_forks[philo->id]));
		print_wmutex(philo, "has taken a fork");
		pthread_mutex_unlock(&(philo->info->m_forks[philo->id]));
		usleep2(philo->info,philo->info->ttd);
		print_wmutex(philo, "die");
		philo->info->status = 1;
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->info->status != 1)
	{
		eat(philo);
		print_wmutex(philo, "is sleeping");
		usleep2(philo->info, philo->info->tts);
		print_wmutex(philo, "is thinking");
	}
	return (0);
}
