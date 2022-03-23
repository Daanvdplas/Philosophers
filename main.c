/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:02:31 by dvan-der          #+#    #+#             */
/*   Updated: 2022/03/22 18:02:38 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Programm requires 4 or 5 arguments:
// number_of_philosophers, time_to_die, time_to_eat, time_to_sleep
// and (optional) number_of_times_each_philophers_must_eat.

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Sorry, you gave too little arguments", 2);
		return (EXIT_FAILURE);
	}
	else if (argc == 5 || argc == 6)
	{
		if (philosophers(argv))
		{
			ft_putendl_fd("Sorry, you gave incorrect arguments", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
