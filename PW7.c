/* *************************************************************************** */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   PW7.c                                               :+:      :+:    :+:   */
/*                                                     +:+ +:+         +:+     */
/*   By  -----------------------------------------  +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:21:02 by --------           #+#    #+#             */
/*   Updated: 2025/03/12 14:32:26 by --------          ###   ########.fr       */
/*                                                                             */
/* *************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void print_res(int *arr, int len,  int *used)
{
	int i = 0;
	int first =1;

	while(i < len)
	{
		if(used[i])
		{
			if(first == 1)
				printf("%d",arr[i]);
			if(first == 0)
				printf(" %d",arr[i]);
			first = 0;
		}
		i++;
	}
	printf("\n");
}

void powerset(int target, int *arr, int len, int pos, int sum, int *used)
{
	if(sum == target)
	{
		print_res(arr, len, used);
		return;
	}
	if(sum > target || pos >= len)
		return;

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
	int len 	= ac - 2;
	int i		= 0;
	int target 	= atoi(av[1]);

	arr			= malloc(sizeof(int) * len);
	used 		= calloc(len, sizeof(int));

	while(i < len)
	{
		arr[i] 	= atoi(av[i + 2]);
		i++;
	}

	powerset(target, arr, len, 0, 0, used);
	free(arr);
	free(used);

	return 0;
}