/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:16 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:23:23 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	int		nbr;
	int		p_n;
	size_t	i;

	p_n = 1;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p_n = -1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			nbr = (nbr * 10) + (str[i] - '0');
		else
			return (ERROR);
		i++;
	}
	return (nbr * p_n);
}
