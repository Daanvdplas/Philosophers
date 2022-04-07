/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:02:55 by dvan-der          #+#    #+#             */
/*   Updated: 2022/03/28 09:14:06 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

# define STOP 0
# define ERROR -1
# define UNSPECIFIED -2
# define SLEEP 3
# define EAT 4
# define THINK 5
# define LEFT_FORK 6
# define RIGHT_FORK 7
# define DIE 8

struct	s_rules;

typedef struct s_philo
{
	pthread_t			thread_id;
	int					id;
	int					x_eaten;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	bool				finished;
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
	pthread_mutex_t		write_lock;
	pthread_mutex_t		eat_lock;
	pthread_mutex_t		time_lock;
	pthread_mutex_t		game_over_lock;
	pthread_mutex_t		*forks;
	t_philo				*philo;
}	t_rules;

int			philosophers(char **argv);
t_rules		*init_all(char **argv);
int			play_game(t_rules *rules);
long long	get_time(void);
long long	time_diff(long long pres, long long past);
int			all_philos_ate(t_philo *philo, t_rules *rules);
int			a_philo_died(t_philo philo, t_rules *rules);
void		pause_func(int pause_t, t_rules *rules);
void		action_print(int type, t_philo *philo);
bool		check_if_game_over(t_rules *rules);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
#endif
