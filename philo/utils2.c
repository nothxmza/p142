/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:24:56 by hamza             #+#    #+#             */
/*   Updated: 2022/09/17 20:43:58 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usleep2(t_info *p, long long time)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
	{
		if (p->status == 1)
			break ;
		usleep(100);
	}
}

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
