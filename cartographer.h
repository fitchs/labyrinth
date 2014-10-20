#ifndef CARTOGRAPHER_H_
# define CARTOGRAPHER_H_

# define CELL(X, Y) ((Y) * (g_size) + (X))
# define IS_INBOUND(X, Y) (X >= 0 && Y >= 0 && X < g_size && Y < g_size)

enum e_direction
{
	LEFT,
	TOP,
	RIGHT,
	BOTTOM,
};

extern int g_size;

char *gen_matrix(int size);
void show_matrix(char *matrix);

#endif /* !CARTOGRAPHER_H_ */
