/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:32:13 by aareslan          #+#    #+#             */
/*   Updated: 2025/11/19 13:32:14 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void	ft_print_error(char **dst, char **str, int free1, int free2)
{
	if (free1 == 1)
		free(dst);
	if (free2 == 1)
		free(str);
	perror("ERROR: ");
	exit(1);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i = 0;
	char	*join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (*s1)
	{
		join[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		join[i] = *s2;
		s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}

void	ft_check_replace(char **str, char *arg)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_str;
	char	*dst;
	char	*src;

	new_str = malloc(ft_strlen(*str) + 1);
	len = ft_strlen(arg);
	if (!new_str)
	{
		free(*str);
		perror("ERROR: ");
		exit(1);
	}
	src = *str;
	dst = new_str;
	while (*src)
	{
		i = 0;
		while(arg[i] && src[i] == arg[i])
			i++;
		if (i == len)
		{
			j = 0;
			while (j < len)
			{
				*dst = '*';
				dst++;
				j++;
			}
			src += len;
		}
		else
		{
			*dst = *src;
			dst++;
			src++;
		}
	}
	*dst = '\0';
	free(*str);
	*str = new_str;
}

int	main(int ac, char **av)
{
	char	*dst;
	char	*str;
	char	*tmp;
	ssize_t	line;

	if (ac != 2 || av[1][0] == '\0')
		return (1);
	str = calloc(1, 1);
	dst = malloc((size_t)BUFFER_SIZE + 1);
	if(!dst)
		ft_print_error(&dst, &str, 0, 0);
	line = 1;
	while (line > 0)
	{
		line = read(0, dst, BUFFER_SIZE);
		if (line == -1)	
			ft_print_error(&dst, &str, 1, 1);
		dst[line] = '\0';
		tmp = ft_strjoin(str, dst);
		if (!tmp)
			ft_print_error(&dst, &str, 1, 1);
		free(str);
		str = tmp;
	}
	free(dst);
	ft_check_replace(&str, av[1]);
	printf("%s", str);
	free(str);
	return (0);
}
