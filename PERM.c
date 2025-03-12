/* *************************************************************************** */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   PERM.c                                              :+:      :+:    :+:   */
/*                                                     +:+ +:+         +:+     */
/*   By:------------------------------------------   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:52:16 by-----------         #+#    #+#             */
/*   Updated: 2025/03/12 15:09:17 by ----------        ###   ########.fr       */
/*                                                                             */
/* *************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	char	*str;
	char	*curr;
	int		*used;
	int		len;
}	t_data;

void sort_liste(char *str)
{
	int		i = 0;
	int		j = 0;
	char 	tmp;

	while(str[i])
	{
		j = i + 1;
		while(str[j])
		{
			if(str[i] > str[j])
			{
				tmp		= str[i];
				str[i] 	= str[j];
				str[j] 	= tmp;
			}
			j++;
		}
		i++;
	}
}

int ft_len(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

void init_data(t_data *data, char *str)
{
	data->str 	= str;
	data->len 	= ft_len(str);
	data->curr	= malloc(sizeof(char) * data->len + 1);
	data->used 	= calloc(data->len, sizeof(int));

	data->curr[data->len] = '\0';
}

void permutation(t_data *data, int pos)
{
	int i = 0;
	if(pos == data->len)
	{
		puts(data->curr);
		return;
	}
	while(i < data->len)
	{
		if(data->used[i] == 0)
		{
			data->used[i] = 1;
			data->curr[pos] = data->str[i];
			permutation(data, pos + 1);
			data->used[i] = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_data	data;

	if(ac != 2)
		return 1;
	sort_liste(av[1]);
	init_data(&data, av[1]);
	permutation(&data, 0);
	free(data.curr);
	free(data.used);
	return 0;
}
