/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:20:14 by hterras           #+#    #+#             */
/*   Updated: 2022/09/20 14:21:41 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*philo;

	if (argc == 5 || argc == 6)
	{
		philo = info_init();
		if (!ft_check(argc, argv, philo))
			return (0);
		if (!philo_init())
			return (0);
		if (!init_mutex(philo))
			return (0);
		if (!create_philo(philo))
			return (0);
	}
	else
		printf("error: number of argument");
}
