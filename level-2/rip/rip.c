/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:32:38 by aareslan          #+#    #+#             */
/*   Updated: 2025/11/19 13:32:39 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int countinvalidpar(char *str)
{
    int left;
    int right;
    int i;

    left = 0;
    right = 0;
    i = 0;

    while (str[i])
    {
        if (str[i] == '(')
            left++;
        else if (str[i] == ')')
        {
            if (left > 0)
                left--;
            else
                right++;
        }
        i++;
    }
    return (left + right);
}

void removeinvalidpar(char *str, int total, int removed, int idx)
{
    int empty;
    int i;
    char tmp;

    if (total == removed && !countinvalidpar(str))
    {
        empty = 1;
        i = 0;
        while (str[i])
        {
            if (str[i] != ' ')
            {
                empty = 0;
                break;
            }
            i++;
        }
        if (empty)
            write(1, "\n", 1);
        else
            puts(str);
        return;
    }

    i = idx;
    while (str[i])
    {
        if (str[i] == '(' || str[i] == ')')
        {
            tmp = str[i];
            str[i] = ' ';
            removeinvalidpar(str, total, removed + 1, i);
            str[i] = tmp;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int min;

    if (ac != 2 || !av[1][0])
        return (1);

    min = countinvalidpar(av[1]);
    removeinvalidpar(av[1], min, 0, 0);
    return (0);
}
