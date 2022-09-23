/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:40 by hterras           #+#    #+#             */
/*   Updated: 2022/09/22 13:45:29 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo(t_info *p)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	p->start_time = get_time();
	while (++i < p->nop)
	{
		p->philosopher[i].id = i;
		p->philosopher[i].info = p;
		if (pthread_create(&(p->philosopher[i].thread), NULL, routine_philo,
				&p->philosopher[i]))
		{
			return (ft_exit("Create philo fail"));
		}
		p->philosopher[i].last_meal = p->start_time;
	}
	dead(p);
	i = -1;
	while (++i < p->nop)
		pthread_join(p->philosopher[i].thread, NULL);
	j = destroy(p);
	return (0);
}

int	destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nop)
	{
		if (pthread_mutex_destroy(&(info->m_forks[i])))
			return (ft_exit("Destroy forks fail"));
	}
	if (pthread_mutex_destroy(&(info->m_print)))
		return (ft_exit("Destroy print fail"));
	if (pthread_mutex_destroy(&(info->m_eat)))
		return (ft_exit("Destroy meal fail"));
	return (0);
}
