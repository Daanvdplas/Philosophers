/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:26:58 by dvan-der          #+#    #+#             */
/*   Updated: 2022/03/25 08:43:03 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Pause the thread for pause_t time, while checking if a philo has died.
void	pause_func(int pause_t, t_rules *rules)
{
	long long	past_time;
	long long	pres_time;

	past_time = get_time();
	while (1)
	{
		pres_time = get_time();
		if (time_diff(pres_time, past_time) > pause_t * 1000)
			break ;
		usleep(100);
		if (check_if_game_over(rules))
			break ;
	}
	return ;
}

// An action type is given, the function prints the matching string to the
// std out.
void	action_print(int type, t_philo *philo)
{
	int		time;

	pthread_mutex_lock(&philo->rules->write_lock);
	time = (int)(time_diff(get_time(), philo->rules->start_time)) / 1000;
	if (check_if_game_over(philo->rules))
	{
		pthread_mutex_unlock(&philo->rules->write_lock);
		return ;
	}
	if (type == DIE)
		printf("At %i, philo %i died\n", time, philo->id);
	else if (type == EAT)
		printf("At %i, philo %i is eating\n", time, philo->id);
	else if (type == SLEEP)
		printf("At %i, philo %i is sleeping\n", time, philo->id);
	else if (type == THINK)
		printf("At %i, philo %i is thinking\n", time, philo->id);
	else if (type == LEFT_FORK)
		printf("At %i, philo %i has taken his left fork\n", time, philo->id);
	else if (type == RIGHT_FORK)
		printf("At %i, philo %i has taken his right fork\n", time, philo->id);
	pthread_mutex_unlock(&philo->rules->write_lock);
	return ;
}

// Checks if the game is over or not.
bool	check_if_game_over(t_rules *rules)
{
	bool	game_over;

	pthread_mutex_lock(&rules->game_over_lock);
	if (rules->a_philo_died || rules->all_philo_ate)
		game_over = true;
	else
		game_over = false;
	pthread_mutex_unlock(&rules->game_over_lock);
	return (game_over);
}

// Checks if a philo must die by comparing the time_to_die
// and the amount of time has past since it last ate.
int	a_philo_died(t_philo philo, t_rules *rules)
{
	long long	time;

	pthread_mutex_lock(&rules->time_lock);
	time = time_diff(get_time(), philo.last_meal);
	pthread_mutex_unlock(&rules->time_lock);
	if ((time / 1000) > rules->time_to_die)
	{
		action_print(DIE, &philo);
		pthread_mutex_lock(&rules->game_over_lock);
		rules->a_philo_died = true;
		pthread_mutex_unlock(&rules->game_over_lock);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// Check if all philos have eaten by comparing the nbr_of_meals
// (if specified) and the amount of time each philo has eaten.
int	all_philos_ate(t_philo *philo, t_rules *rules)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&rules->eat_lock);
	while (i < rules->nbr_of_philo && philo[i].x_eaten >= rules->nbr_of_meals
		&& rules->nbr_of_meals != UNSPECIFIED)
		i++;
	pthread_mutex_unlock(&rules->eat_lock);
	if (i == rules->nbr_of_philo)
	{
		pthread_mutex_lock(&rules->game_over_lock);
		rules->all_philo_ate = true;
		pthread_mutex_unlock(&rules->game_over_lock);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
