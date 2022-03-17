# include "philo.h"

philo_eat()
{
	pthread_mutex_lock(rules->forks[philo->left_fork]);
	action(lfork);
	pthread_mutex_lock(rules->forks[philo->right_fork]);
	action(rfork);
	pthread_mutex_lock(rules->to_eat);
	action(eating);
	philo->last_meal = get_time();
	pthread_mutex_unlock(rules->to_eat);
	pthread_mutex_unlock(rules->forks[philo->right_fork]);
	pthread_mutex_unlock(rules->forks[philo->left_fork]);
	philo->x_eaten++;
}

a_philo(void *void_philo)
{
	t_philo	*philo;
	t_rules	*rules;
	int		i;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(rules->time_to_eat * 1000);
	while (!rules->a_philo_died)
	{
		philo_eat(philo, rules);
		if (rules->all_philo_ate)
			break ;
		

int	play_game(t_rules *rules)
{
	t_philo	*philo;
	int		i;

	philo = rules->philo;
	rules->start_time = get_time();
	i = 0;
	while (i < rules->nbr_of_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, a_philo, &(philo[i])))
			return (EXIT_FAILURE);
		philo[i].last_meal = get_time();
		i++;
	}
	return (EXIT_SUCCESS);
}
		

