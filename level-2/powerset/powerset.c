/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:32:33 by aareslan          #+#    #+#             */
/*   Updated: 2025/11/19 13:32:35 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	find_subsets(int *arr, int n, int tgt)
{
	int	total;
	int	sum;
	int	mask;
	int	first;
	int j;

	total = 1 << n;
	mask = 0;
	while (mask < total)
	{
		sum = 0;
		first = 1;
		j = 0;
		while(j < n)
		{
			if (mask & (1 << j))
				sum += arr[j];
			j++;
		}
		if (sum == tgt)
		{
			j = 0;
			while(j < n)
			{
				if (mask & (1 << j))
				{
					if (!first)
						printf(" ");
					printf("%d", arr[j]);
					first = 0;
				}
				j++;
			}
			printf("\n");
		}
		mask++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	tgt;
	int	n;

	if (ac < 3)
		return (1);
	tgt = atoi(av[1]);
	n = ac - 2;
	int	arr[n];
	i = 0;
	while (i < n)
	{
		arr[i] = atoi(av[i + 2]);
		i++;
	}
	find_subsets(arr, n, tgt);
	return (0);
}
