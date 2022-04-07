/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:02:31 by dvan-der          #+#    #+#             */
/*   Updated: 2022/03/23 17:15:40 by dvan-der         ###   ########.fr       */
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
		printf("Sorry, you gave too little arguments\n");
		return (EXIT_FAILURE);
	}
	else if (argc == 5 || argc == 6)
	{
		if (philosophers(argv))
		{
			printf("Sorry, you gave incorrect arguments\n");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
