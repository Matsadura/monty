#include "monty.h"


void free_grid(char *lines[][3])
{
	int i, j;

	for (i = 0; lines[i][0] ; i++)
	{
		for (j = 0; lines[i][j]; j++)
		{
			free(lines[i][j]);
		}
	}
}
