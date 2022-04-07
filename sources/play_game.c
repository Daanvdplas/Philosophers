/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:35:42 by dvan-der          #+#    #+#             */
/*   Updated: 2022/03/28 09:26:50 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Join all threads, destroy all mutexes and free malloced variables.
static void	exit_game(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_of_philo)
	{
		pthread_mutex_lock(&rules->game_over_lock);
		if (rules->philo[i].finished)
			i++;
		pthread_mutex_unlock(&rules->game_over_lock);
	}
	i = 0;
	while (i < rules->nbr_of_philo)
	{
		pthread_mutex_destroy(&(rules->forks[i]));
		pthread_join(rules->philo[i].thread_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&rules->write_lock);
	pthread_mutex_destroy(&rules->eat_lock);
	pthread_mutex_destroy(&rules->time_lock);
	pthread_mutex_destroy(&rules->game_over_lock);
	free(rules->forks);
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

	philo = rules->philo;
	while (1)
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
	}
	return ;
}

// Here a philo will eats when picking up his two forks next to him.
static void	philo_eat(t_philo *philo, t_rules *rules)
{
	pthread_mutex_lock(&rules->forks[philo->left_fork]);
	action_print(LEFT_FORK, philo);
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_unlock(&rules->forks[philo->left_fork]);
		pause_func(rules->time_to_die, rules);
		return ;
	}
	pthread_mutex_lock(&rules->forks[philo->right_fork]);
	action_print(RIGHT_FORK, philo);
	action_print(EAT, philo);
	pthread_mutex_lock(&rules->time_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&rules->time_lock);
	pause_func(rules->time_to_eat, rules);
	pthread_mutex_unlock(&rules->forks[philo->left_fork]);
	pthread_mutex_unlock(&rules->forks[philo->right_fork]);
	pthread_mutex_lock(&rules->eat_lock);
	philo->x_eaten++;
	pthread_mutex_unlock(&rules->eat_lock);
	return ;
}

// A philo's life cycle: eating, sleeping and thinkin untill the
// game is over.
static void	*a_philo(void *void_philo)
{
	t_philo	*philo;
	t_rules	*rules;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	if (philo->id % 2)
		pause_func(rules->time_to_eat, rules);
	while (1)
	{
		action_print(THINK, philo);
		philo_eat(philo, philo->rules);
		action_print(SLEEP, philo);
		pause_func(rules->time_to_sleep, rules);
		if (check_if_game_over(rules))
			break ;
	}
	pthread_mutex_lock(&philo->rules->game_over_lock);
	philo->finished = true;
	pthread_mutex_unlock(&philo->rules->game_over_lock);
	return (NULL);
}	

// Creating the threads/philos. Then it will check the game and
// eventually end the game.
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
		pthread_mutex_lock(&rules->time_lock);
		philo[i].last_meal = get_time();
		pthread_mutex_unlock(&rules->time_lock);
		i++;
	}
	game_checker(rules);
	exit_game(rules);
	return (EXIT_SUCCESS);
}
