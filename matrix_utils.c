#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cartographer.h"

void show_matrix(char *matrix)
{	
	int x;
	int y;

	y = 0;
	while (y < g_size)
	{
		x = 0;
		while (x < g_size)
		{
			printf("%c", matrix[CELL(x, y)]);
			x++;
		}
		y++;
		printf("\n");
	}
}


char *gen_matrix(int square_size)
{
	char	*res;
	size_t	mem_size;

	mem_size = sizeof(char) * square_size * square_size;
	res = malloc(mem_size);
	if (res == NULL)
		return (NULL);
	memset(res, 'X', mem_size);
	return (res);
}
