#include "monty.h"

/**
 * isInteger - checks if it's an integer
 * @val: the string to check
 * Return: 0 if it's an int, 1 otherwise
 */
int isInteger(char *val)
{
	int i = 0;

	if (val[i] == '-')
		i++;

	for (; val[i] != '\0'; i++)
	{
		if (isdigit(val[i]) == 0)
			return (1);
	}
	return (0);
}
