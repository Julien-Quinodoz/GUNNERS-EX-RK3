/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PW14.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinodo <jquinodo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:58:10 by jquinodo          #+#    #+#             */
/*   Updated: 2025/03/13 18:10:20 by jquinodo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void powerset(int target,int *arr,int len, int pos, int sum, int *used, int to_print)
{
	int i = 0;
	int first = 1;

	if(sum == target && to_print == 1)
	{
		while(i < len)
		{
			if(used[i])
			{
				if(first == 1)
					printf("%d", arr[i]);
				if(first == 0)
					printf(" %d", arr[i]);
				first = 0;
			}
			i++;
		}
		printf("\n");
		//return;
	}
	if(sum > target || pos >=len)
		return;

	used[pos] = 1;
	powerset(target, arr,len, pos + 1, sum + arr[pos], used, 1);
	used[pos] = 0;
	powerset(target, arr,len, pos + 1, sum, used, 0);
}
int main(int ac, char **av)
{
	if(ac < 2)
		return 1;

	int i = 0;
	int *arr;
	int *used;
	int len = ac - 2 ;
	int target = atoi(av[1]);

	arr = malloc(sizeof(int) * len);
	used = calloc(len, sizeof(int));

	while(i < len)
	{
		arr[i] = atoi(av[i+2]);
		i++;
	}

	powerset(target, arr, len, 0, 0, used, 0);
	free(used);
	free(arr);
	return 0;
}