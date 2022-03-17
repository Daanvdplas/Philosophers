# include "philosophers.h"

static int	check_input(t_rules *rules, bool flag)
{
	if (rules->nbr_of_philo < 2 ||
		rules->nbr_of_philo > 200 ||
		rules->time_to_die < 0 ||
		rules->time_to_eat < 0 ||
		rules->time_to_sleep < 0)
	{
		free(rules);
		return (EXIT_FAILURE);
	}
	else if (rules->nbr_of_meals < 0 && !flag)
	{
		free(rules);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_rules(char **argv, t_rules *rules)
{
	bool	flag;

	flag = false;
	rules->all_philo_ate = false;
	rules->a_philo_died = false;
	rules->nbr_of_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->nbr_of_meals = ft_atoi(argv[5]);
	else
	{
		flag = true;
		rules->nbr_of_meals = UNSPECIFIED;
	}
	if (check_input(rules, flag))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_mutex(t_rules *rules)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(rules->nbr_of_philo * sizeof(pthread_mutex_t));
	if (!forks)
		return (EXIT_FAILURE);
	i = 0;
	while (i < rules->nbr_of_philo)
	{
		if (pthread_mutex_init(&(forks[i]), NULL))
			return (EXIT_FAILURE);
		i++;
	}
	rules->forks = forks;
	if (pthread_mutex_init(&(rules->to_write), NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(rules->to_eat), NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_philos(t_rules *rules)
{
	t_philo	*philo;
	int		i;

	philo = malloc(rules->nbr_of_philo * sizeof(t_philo));
	if (!philo)
		return (EXIT_FAILURE);
	i = 0;
	while (i < rules->nbr_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].x_eaten = 0;
		philo[i].left_fork = i + 1;
		philo[i].right_fork = (i + 1) % rules->nbr_of_philo;
		philo[i].last_meal = 0;
		philo[i].rules = rules;
		i++;
	}
	rules->philo = philo;
	return (EXIT_SUCCESS);
}

t_rules	*init_all(char **argv)
{
	t_rules *rules;

	rules = (t_rules *)malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);	
	if (init_rules(argv, rules))
		return (NULL);	
	if (init_mutex(rules))
		return (NULL);
	if (init_philos(rules))
		return (NULL);
	return (rules);
}