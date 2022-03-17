/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutgercappendijk <rutgercappendijk@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:42:06 by rcappend          #+#    #+#             */
/*   Updated: 2022/01/08 12:00:24 by rutgercappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_new_str(char const *str, char c, int len)
{
	char	*new_str;
	int		i;

	new_str = (char *)ft_calloc(len, sizeof(char));
	ft_check_malloc(new_str, "make_new_str");
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			new_str[i] = *str;
			i++;
		}
		str++;
	}
	return (new_str);
}

char	*ft_filter_str(char const *str, char c)
{
	int		i;
	int		len;
	char	*new_str;

	if (!str)
		return (NULL);
	i = 0;
	len = 0;
	while (str[i])
	{
		i++;
		if (str[i] != c)
			len++;
	}
	len++;
	new_str = make_new_str(str, c, len);
	return (new_str);
}
