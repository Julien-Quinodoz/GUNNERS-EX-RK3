/*
Board	Total Solutions | wc -l
nb 1 --> 1
nb 2 --> 0
nb 3 --> 0
nb 4 --> 2
nb 5 --> 10
nb 6 --> 4
nb 7 --> 40
nb 8 --> 92
nb 9 --> 352
nb 10 --> 724
*/

#include <stdio.h>
#include <stdlib.h>

int is_safe(int *board, int col, int row)
{
	int i = 0;

	while (i < col)
	{
		if (board[i] == row)
			return 0;
		if (board[i] - row == col - i || board[i] - row == i - col)
			return 0;
		i++;
	}
	return 1;
}

void print_res(int *board, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i < n - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void solve_NQ(int *board, int col, int n)
{
	int row = 0;

	if (col == n)
	{
		print_res(board, n);
		return;
	}
	while (row < n)
	{
		if (is_safe(board, col, row) == 1)
		{
			board[col] = row;
			solve_NQ(board, col + 1, n);
		}
		row++;
	}
}

int main(int ac, char **av)
{
	int n;
	int *board;

	if (ac != 2)
		return 1;
	n = atoi(av[1]);
	if (n < 1)
		return 1;
	board = malloc(sizeof(int) * n);
	if(!board)
		return 1;

	solve_NQ(board, 0, n);

	free(board);
	return 0;
}
