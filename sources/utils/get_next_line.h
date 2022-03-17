/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:21:07 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:21:09 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

int		check_line(char *line);
void	change_buffer(char *buffer, int buffer_size);
void	make_newline(char *new_line, char *line, char *buffer, int buffer_size);
char	*add_buffer(char *line, char *buffer, int buffer_size, int size_line);
int		check_buffer(char *buffer);
char	*get_next_line(int fd);

#endif