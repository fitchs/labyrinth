#include "cartographer.h"
#include <stdio.h>
#include <stdlib.h>

int g_size;

static int usage(void)
{
	fprintf(stderr, "the labyrinth must be a square of size"
			"greater than 8, smaller than 30, and be even\n");
	fprintf(stderr, "dedale: usage: dedale size\n");
	return (EXIT_FAILURE);
}


int main(int argc, char **argv)
{
	char *matrix;

	if (argc != 2)
		return (usage());
	g_size = atoi(argv[1]);
	my_srand(g_size);
	if (g_size > 229 || g_size < 9 || g_size % 2 == 0)
		return (usage());
	if ((matrix = gen_matrix(g_size)) == NULL)
		return (EXIT_FAILURE);
	make_laby(matrix);
	show_matrix(matrix);
	free(matrix);
	return (EXIT_SUCCESS);
}

