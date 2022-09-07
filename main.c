#include "philo.h"

int main(int argc,char **argv)
{
	t_info *philo = NULL;

	if (argc == 5 || argc == 6)
	{
		philo = info_init();
		ft_check(argc, argv, philo);
		philo_init();
		init_mutex(philo);
		create_philo(philo);
		//printf("nop:%d  ttd:%d  tte:%d  tts:%d  nte:%d\n",philo->nop,philo->ttd,philo->tte, philo->tts, philo->nte);
	}
	else
		printf("error: number of argument");
}