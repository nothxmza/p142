/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hterras <hterras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:20:14 by hterras           #+#    #+#             */
/*   Updated: 2022/09/11 16:08:35 by hterras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*philo;

	if (argc == 5 || argc == 6)
	{
		philo = info_init();
		ft_check(argc, argv, philo);
		philo_init();
		init_mutex(philo);
		create_philo(philo);
	}
	else
		printf("error: number of argument");
}
