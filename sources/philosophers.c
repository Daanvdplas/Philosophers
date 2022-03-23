/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:03:20 by dvan-der          #+#    #+#             */
/*   Updated: 2022/03/22 18:21:20 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philosophers(char **argv)
{
	t_rules	*rules;

	rules = init_all(argv);
	if (!rules)
		return (EXIT_FAILURE);
	if (play_game(rules))
		return (EXIT_FAILURE);
	system("leaks philo");
	return (EXIT_SUCCESS);
}
