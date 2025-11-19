/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:32:26 by aareslan          #+#    #+#             */
/*   Updated: 2025/11/19 13:32:29 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	sorted(char *str)
{
	int		i = 0;
	int		j;
	char	tmp;

	while (str[i])
	{
		j = i + 1;
		while(str[j])
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	perm(char *str, char *result, int *used, int dep, int len)
{
	int	i = 0;
	if (dep == len)
	{
		while (i < len)
		{
			write(1, &result[i], 1);
			i++;
		}
		write(1, "\n", 1);
		return ;
	}
	while (i < len)
	{
		if (used[i])
		{
			i++;
			continue;
		}
		used[i] = 1;
		result[dep] = str[i];
		perm(str, result, used, dep + 1, len);
		used[i] = 0;
		i++;
	}
}

int main(int ac, char **av)
{
	int		i = 0;
	int		len;
	int 	*used;
	char	*result;

	if (ac != 2)
		return (1);
	while (av[1][i])
		i++;
	len = i;
	result = malloc(len + 1);
	used = calloc(len, sizeof(int));
	sorted(av[1]);
	perm(av[1], result, used, 0, len);
	free(result);
	free(used);
	return(0);
}
