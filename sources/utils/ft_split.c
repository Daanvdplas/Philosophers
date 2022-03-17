/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:21:54 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:21:56 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_splitted_arr(char **split_arr)
{
	size_t	i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
}

static int	count_str(const char *s, char c, int hor_i)
{
	size_t	i;

	i = 0;
	while (s[hor_i] != c && s[hor_i] != '\0')
	{
		hor_i++;
		i++;
	}
	return (i);
}

static char	**fill_spl_arr(char **split_arr, int splits, const char *s, int c)
{
	int	hor_i;
	int	vert_i;
	int	length;

	hor_i = 0;
	vert_i = 0;
	length = 0;
	while (vert_i < splits)
	{
		while (s[hor_i] == c)
			hor_i++;
		length = count_str(s, c, hor_i);
		split_arr[vert_i] = (char *)ft_calloc(length + 1, sizeof(char));
		ft_check_malloc(split_arr[vert_i], "fill_spl_arr");
		ft_strlcpy(split_arr[vert_i], &s[hor_i], length + 1);
		hor_i += length;
		vert_i++;
	}
	return (split_arr);
}

int	ft_count_splits(char const *s, char c)
{
	int		counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
			counter++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char			**split_arr;
	unsigned int	splits;

	if (!s)
		return (NULL);
	splits = ft_count_splits(s, c);
	split_arr = (char **)ft_calloc(splits + 1, sizeof(char *));
	ft_check_malloc(split_arr, "ft_split");
	if (!*s || splits == 0)
		return (split_arr);
	if (!fill_spl_arr(split_arr, splits, s, c))
	{
		free_splitted_arr(split_arr);
		free(split_arr);
		return (NULL);
	}
	return (split_arr);
}
