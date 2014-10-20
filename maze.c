#include <unistd.h>
#include "cartographer.h"

static int g_cross[][2] =
{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

int is_wall(char *matrix, int x, int y)
{
	return (IS_INBOUND(x, y) && matrix[CELL(x, y)] == 'X');
}

void rec(char *matrix, int X, int Y, enum e_direction direction)
{
	int add_x;
	int add_y;
	int random_number;

	//show_matrix(matrix);
	direction = direction % 4;
	add_x = g_cross[direction][0];
	add_y = g_cross[direction][1];

	X += add_x;
	Y += add_y;
	if (!is_wall(matrix, X + add_x, Y + add_y))
		return ;
	matrix[CELL(X, Y)] = ' ';
	matrix[CELL(X += add_x, Y += add_y)] = ' ';

	random_number = my_rand();
	rec(matrix, X, Y, random_number);
	rec(matrix, X, Y, random_number + 3);
	rec(matrix, X, Y, random_number + 1);
	rec(matrix, X, Y, random_number + 2);
}

void make_laby(char *matrix)
{
	int startX;
	int startY;
	
	startX = 1;
	startY = 1;

	matrix[CELL(startX, startY)] = ' ';
	rec(matrix, startX, startY, RIGHT);
}

