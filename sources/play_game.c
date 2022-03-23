/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:35:42 by dvan-der          #+#    #+#             */
/*   Updated: 2022/03/23 16:36:54 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Join all threads, destroy all mutexes and free malloced variables.
static void	exit_game(t_rules *rules)
{
	int	i;

	free(rules->forks);
	i = 0;
	while (i < rules->nbr_of_philo)
	{
		pthread_join(rules->philo[i].thread_id, NULL);
		pthread_mutex_destroy(&(rules->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&rules->write_lock);
	pthread_mutex_destroy(&rules->eat_lock);
	free(rules->philo);
	free(rules);
	return ;
}

// Untill a philo dies or if all philos have eaten. It will
// loop through all the philosophers, as a referee.
static void	game_checker(t_rules *rules)
{
	int			i;
	t_philo		*philo;
	bool		game_over;

	philo = rules->philo;
	game_over = check_if_game_over(rules);
	while (!game_over)
	{
		i = 0;
		while (i < rules->nbr_of_philo)
		{
			if (a_philo_died(philo[i], rules))
				return ;
			i++;
		}
		if (all_philos_ate(philo, rules))
			break ;
		usleep(100);
		game_over = check_if_game_over(rules);
	}
	return ;
}

// A philo's life cycle: eating, sleeping and thinkin untill the
// game is over.
static void	*a_philo(void *void_philo)
{
	t_philo	*philo;
	t_rules	*rules;
	bool	game_over;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	if (philo->id % 2)
		pause_func(rules->time_to_eat, rules);
	game_over = check_if_game_over(rules);
	while (!game_over)
	{
		action_print(THINK, philo);
		philo_eat(philo, philo->rules);
		if (check_if_game_over(rules))
			break ;
		action_print(SLEEP, philo);
		pause_func(rules->time_to_sleep, rules);
		game_over = check_if_game_over(rules);
	}
	return (NULL);
}	

// Creating the threads/philos. Then it will check the game and
// eventually end the game.
int	play_game(t_rules *rules)
{
	t_philo	*philo;
	int		i;

	philo = rules->philo;
	pthread_mutex_lock(&rules->time_lock);
	rules->start_time = get_time();
	pthread_mutex_unlock(&rules->time_lock);
	i = 0;
	while (i < rules->nbr_of_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, a_philo, &(philo[i])))
			return (EXIT_FAILURE);
		pthread_mutex_lock(&rules->time_lock);
		philo[i].last_meal = get_time();
		pthread_mutex_unlock(&rules->time_lock);
		i++;
	}
	game_checker(rules);
	exit_game(rules);
	return (EXIT_SUCCESS);
}
