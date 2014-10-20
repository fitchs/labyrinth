#include "cartographer.h"

static unsigned int g_seed = 0;

void my_srand(unsigned int seed)
{
	g_seed = seed;
}

unsigned int my_rand(void)
{
	unsigned int new_number = g_seed;

	new_number ^= new_number >> 12;
	new_number ^= new_number << 5;
	new_number ^= new_number >> 20;

	new_number *= 49387493;
	g_seed = new_number;
	return (new_number);
}
