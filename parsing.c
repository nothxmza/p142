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
	ft_check_nbr(argv, philo);
}

void	ft_check_num(char	**argv)
{
	int	i = 1;
	int	j = 0;
	while(argv[i])
	{
		while(argv[i][j])
		{
			if(!ft_isalnum(argv[i][j]))
			{
				printf("error: not only digit");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void ft_check_nbr(char **argv, t_info *philo)
{
	if (philo->nop < 1 || philo->nop > 200 || philo->ttd < 60 || philo->tte < 60 || philo->tts < 60 || philo->nte < 0)
	{
		printf("error: valeur incorrettes");
		exit(EXIT_FAILURE);
	}
}