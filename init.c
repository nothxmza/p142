/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:42:29 by hterras           #+#    #+#             */
/*   Updated: 2022/09/09 15:01:26 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!p->m_forks)
		ft_exit("Erreur de malloc des forks");
}

void	init_mutex(t_info *p)
{
	int	i;

	i = p->nop;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(p->m_forks[i]), NULL))
			ft_exit("mutex init forks fail");
	}
	if (pthread_mutex_init(&(p->m_print), NULL))
		ft_exit("mutex init print fail");
	if (pthread_mutex_init(&(p->m_eat), NULL))
		ft_exit("mutex init print fail");
}
