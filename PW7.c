/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PW7.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:58:10 by jquinodo          #+#    #+#             */
/*   Updated: 2025/03/17 11:47:33 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// !! BUG A CONTROLER : QUAND TARGET EST 0 EXEMPLE : a.out 0 -2 2 -5 5  RETOUR AVEC UN \N EN TROP ????

void powerset(int target, int *arr, int len, int pos, int sum, int *used)
{
    int i = 0;
    int first = 1;

    if (pos >= len)
    {
        if (sum == target)
        {
            while (i < len)
            {
                if (used[i])
                {
                    if (!first)
                        printf(" ");
                    printf("%d", arr[i]);
                    first = 0;
                }
                i++;
            }
            printf("\n");
        }
        return;
    }

    used[pos] = 1;
    powerset(target, arr, len, pos + 1, sum + arr[pos], used);

    used[pos] = 0;
    powerset(target, arr, len, pos + 1, sum, used);
}

int main(int ac, char **av)
{
	if(ac < 2)
		return 1;
	int *arr;
	int *used;
	int target = atoi(av[1]);
	int len = ac -2;
	int i = 0;
	arr = malloc(sizeof(int) * len);
	used = calloc(len , sizeof(int));
	while(i < len)
	{
		arr[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(target, arr, len, 0, 0, used);
	free(used);
	free(arr);
	return 0;
}
