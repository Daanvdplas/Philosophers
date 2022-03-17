/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 13:40:41 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/07 14:16:32 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include "utils.h"

# define UNSPECIFIED -2

struct	s_rules;

typedef struct s_philo
{
	pthread_t			thread_id;
	int					id;
	int					x_eaten;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	struct s_rules		*rules;
}	t_philo;

typedef struct s_rules
{
	int					nbr_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nbr_of_meals;
	int					writing;
	int					meal_check;
	long long			start_time;
	bool				all_philo_ate;
	bool				a_philo_died;
	pthread_mutex_t		to_write;
	pthread_mutex_t		to_eat;
	pthread_mutex_t		*forks;
	t_philo				*philo;
}	t_rules;

int			philosophers(char **argv);
t_rules		*init_all(char **argv);

#endif

