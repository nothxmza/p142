/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:21:28 by hterras           #+#    #+#             */
/*   Updated: 2022/09/09 14:24:39 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || \
			str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	print_wmutex(t_philo *p, char *str)
{
	pthread_mutex_lock(&(p->info->m_print));
	if (p->info->status != 1)
		printf(" %lli %i %s\n", \
			get_time() - p->info->start_time, p->id + 1, str);
	pthread_mutex_unlock(&(p->info->m_print));
}

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
