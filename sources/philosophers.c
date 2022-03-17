# include "philosophers.h"

// arguments: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep
// and (optional) number_of_times_each_philophers_must_eat.



int	philosophers(char **argv)
{
	t_rules	*rules;

	rules = init_all(argv);
	if (!rules)
		return (EXIT_FAILURE);
	if (play_game)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

