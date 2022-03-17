/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:11 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/04 12:22:46 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free_char_array(char **char_array)
{
	int	i;

	i = 0;
	if (!char_array)
		return ;
	while (char_array[i])
	{
		free(char_array[i]);
		i++;
	}
	free(char_array);
	return ;
}
