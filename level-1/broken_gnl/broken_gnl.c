/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:32:05 by aareslan          #+#    #+#             */
/*   Updated: 2025/11/19 13:32:06 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	read_pos;
	static int	index;
	char		*line;
	int			i;

	i = 0;
	line = malloc(4294967295);
	while (1)
	{
		if (read_pos >= index)
		{
			index = read(fd, buffer, BUFFER_SIZE);
			read_pos = 0;
			if (index <= 0)
				break;
		}
		line[i] = buffer[read_pos];
		read_pos++;
		i++;
		if (buffer[read_pos - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
