/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:22:47 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:22:55 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long long n, int p_n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (p_n)
		i++;
	return (i);
}

static char	*make_str(long long n, char *str, int i, int p_n)
{
	str[i] = '\0';
	i--;
	if (n == 0)
	{
		str[i] = '0';
		i--;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	if (p_n)
	{
		str[i] = '-';
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	int			p_n;
	char		*str;
	long long	x;

	p_n = 0;
	x = (long long)n;
	if (n < 0)
	{
		p_n = 1;
		x *= -1;
	}
	i = nbr_len(x, p_n);
	str = malloc(i * sizeof(char) + 1);
	ft_check_malloc(str, "ft_itoa");
	str = make_str(x, str, i, p_n);
	return (str);
}
