#include "monty.h"

void free_grid(char **grid)
{
	int i = 0;

	for (i = 0; grid[i] ; i++)
	{
		free(grid[i]);
	}
}