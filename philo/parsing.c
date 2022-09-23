/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:19:02 by hterras           #+#    #+#             */
/*   Updated: 2022/09/22 13:47:23 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(int argc, char **argv, t_info *philo)
{
	int	i;

	i = ft_check_num(argv);
	if (i == 0)
		return (i);
	if (argc == 5)
	{
		philo->nop = ft_atoi(argv[1]);
		philo->ttd = ft_atoi(argv[2]);
		philo->tte = ft_atoi(argv[3]);
		philo->tts = ft_atoi(argv[4]);
	}
	else if (argc == 6)
	{
		philo->nop = ft_atoi(argv[1]);
		philo->ttd = ft_atoi(argv[2]);
		philo->tte = ft_atoi(argv[3]);
		philo->tts = ft_atoi(argv[4]);
		philo->nte = ft_atoi(argv[5]);
	}
	i = ft_check_nbr(philo);
	return (i);
}

int	ft_check_num(char	**argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isalnum(argv[i][j]))
			{
				return (ft_exit("error: not only digit"));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_nbr(t_info *philo)
{
	if (philo->nop < 1 || philo->nop > 200 || philo->ttd < 60 || \
		philo->tte < 60 || philo->tts < 60 || philo->nte < 0)
	{
		return (ft_exit("error: valeur incorrect"));
	}
	return (1);
}
