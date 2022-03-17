/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_binary_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:25 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/15 17:39:42 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	bin_converter(int nbr, char *binary)
{
	int	i;
	int	calc;

	i = 31;
	while (i > 0)
	{
		calc = nbr / 2;
		if (nbr == calc * 2)
			binary[i] = '0';
		else
			binary[i] = '1';
		nbr /= 2;
		i--;
	}
}

char	*ft_atoi_binary_str(int nbr)
{
	char	*binary;

	binary = (char *)malloc(33 * sizeof(char));
	ft_check_malloc(binary, "ft_atoi_binary_str");
	if (nbr < 0)
	{
		binary[0] = '1';
		bin_converter(nbr + 2147483648, binary);
	}
	else
	{
		binary[0] = '0';
		bin_converter(nbr, binary);
	}
	binary[32] = '\0';
	return (binary);
}
