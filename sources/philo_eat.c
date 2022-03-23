/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:37:08 by dvan-der          #+#    #+#             */
/*   Updated: 2022/03/23 16:48:39 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	help_philo_eat(t_rules *rules, t_philo *philo, int flag)
{
	if (flag == 1)
	{
		pthread_mutex_unlock(&rules->forks[philo->left_fork]);
		pause_func(rules->time_to_die, rules);
	}
	else if (flag == 2)
	{
		pthread_mutex_unlock(&rules->forks[philo->left_fork]);
		pthread_mutex_unlock(&rules->forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_unlock(&rules->forks[philo->left_fork]);
		pthread_mutex_unlock(&rules->forks[philo->right_fork]);
		pthread_mutex_unlock(&rules->eat_lock);
	}
	return ;
}

// Here a philo will eats when picking up his two forks next to him.
void	philo_eat(t_philo *philo, t_rules *rules)
{
	pthread_mutex_lock(&rules->forks[philo->left_fork]);
	action_print(LEFT_FORK, philo);
	if (philo->left_fork == philo->right_fork)
		return (help_philo_eat(rules, philo, 1));
	pthread_mutex_lock(&rules->forks[philo->right_fork]);
	if (check_if_game_over(philo->rules))
		return (help_philo_eat(rules, philo, 2));
	action_print(RIGHT_FORK, philo);
	pthread_mutex_lock(&rules->eat_lock);
	pthread_mutex_lock(&rules->time_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&rules->time_lock);
	if (check_if_game_over(philo->rules))
		return (help_philo_eat(rules, philo, 3));
	action_print(EAT, philo);
	pthread_mutex_unlock(&rules->eat_lock);
	pause_func(rules->time_to_eat, rules);
	pthread_mutex_unlock(&rules->forks[philo->right_fork]);
	pthread_mutex_unlock(&rules->forks[philo->left_fork]);
	philo->x_eaten++;
	return ;
}
