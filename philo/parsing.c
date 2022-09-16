/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:19:02 by hterras           #+#    #+#             */
/*   Updated: 2022/09/09 15:08:41 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check(int argc, char **argv, t_info *philo)
{
	ft_check_num(argv);
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
	ft_check_nbr(philo);
}

void	ft_check_num(char	**argv)
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
				printf("error: not only digit");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_check_nbr(t_info *philo)
{
	if (philo->nop < 1 || philo->nop > 200 || philo->ttd < 60 || \
		philo->tte < 60 || philo->tts < 60 || philo->nte < 0)
	{
		printf("error: valeur incorrettes");
		exit(1);
	}
}
