#include "monty.h"

/**
 * free_grid2 - frees a 2D array
 * @lines: the array
 */
void free_grid2(char *lines[][3], int numTokens)
{
	int i, j;

	for (i = 0; i < numTokens ; i++)
	{
		for (j = 0; lines[i][j]; j++)
			free(lines[i][j]);
	}
}

/**
 * free_grid - frees a 2D array
 * @lines: the array
 */
void free_grid(char *lines[][3])
{
	int i, j;

	for (i = 0; lines[i][0] ; i++)
	{
		for (j = 0; lines[i][j]; j++)
			free(lines[i][j]);
	}
}