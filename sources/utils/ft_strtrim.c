/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:21:23 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:21:24 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	if (!s1)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	str_len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[str_len - i - 1]) && *s1)
		i++;
	str = ft_substr(s1, 0, str_len - i);
	if (!str)
		return (ft_strdup(""));
	return (str);
}
