

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define B_SIZE 42

char	*filter(char *str, char *filter)
{
	int	i = 0;
	int	j = 0;
	int s = 0;
	int	x = 0;
	int	len = 0;

	while (filter[len])
		len++;

	while (str[i])
	{
		j = 0;
		s = i;
		while (str[s] == filter[j] && filter[j])
		{
			j++;
			s++;
		}
		if (j == len)
		{
			x = 0;
			while (x < len)
			{
				str[i + x] = '*';
				x++;
			}
		}
		i++;
	}
	return (str);
}

char *ft_strcat(char *p_buffer, char *buffer)
{
	char *p_tmp;
	p_tmp = p_buffer;

	while(*p_buffer)
		p_buffer++;
	while(*buffer)
	{
		*p_buffer = *buffer;
		p_buffer++;
		buffer++;
	}
	*p_buffer = '\0';

	return(p_tmp);
}

int main(int arc, char **arv)
{
	if(arc != 2)
	{
		printf("error : ./a.out <un argument>\n");
		return(1);
	}
	char buffer[B_SIZE + 1];
	char *p_buffer = NULL;
	int ret = 0;
	int total_size = 0;

	while( (ret = read(0, buffer, B_SIZE)) > 0)
	{
		buffer[ret] = '\0';

		if(total_size == 0)
		{
			p_buffer = (char *)calloc( 1,  sizeof(char) * (ret + 1) );
			if(!p_buffer)
			{
				perror("error calloc");
				return(1);
			}
		}
		else
		{
			p_buffer = (char *)realloc(p_buffer, sizeof(char) * (total_size + ret + 1));
			if(!p_buffer)
			{
				perror("error realloc");
				free(p_buffer);
				return (1);
			}
		}
		total_size = total_size + ret;
		ft_strcat(p_buffer, buffer);
	}

	filter(p_buffer, arv[1]);

	printf("%s",p_buffer);

	free(p_buffer);
	return(0);
}
