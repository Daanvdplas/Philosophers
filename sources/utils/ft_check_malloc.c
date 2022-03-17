/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:09 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/15 17:40:06 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_check_malloc(void *pointer, char *function)
{
	if (!pointer)
	{
		ft_putendl_fd(function, 2);
		ft_putendl_fd(": malloc error", 2);
		exit(1);
	}
	return ;
}
