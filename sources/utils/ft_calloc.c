/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:11 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:23:12 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t num, size_t size)
{
	int		*ptr;

	ptr = (int *)malloc(num * size * sizeof(int));
	ft_check_malloc(ptr, "ft_calloc");
	ft_bzero(ptr, num * size);
	return (ptr);
}
