#include "monty.h"

void exit_err(int flag, char *lines[][3], unsigned int L, char *cmd)
{
	if (flag == 1)
		fprintf(stderr, "L%d: usage: push integer\n", L);
    else if (flag == 3)
        fprintf(stderr, "L%d: can't pint, stack empty\n", L);
    else if (flag == 4)
        fprintf(stderr, "L%d: can't pop an empty stack\n", L);
    else if (flag == 5)
        fprintf(stderr, "L%d: can't swap, stack too short\n", L);
    else if (flag == 6)
        fprintf(stderr, "L%d: can't add, stack too short\n", L);
    else if (flag == 7)
        fprintf(stderr, "L%d: can't sub, stack too short\n", L);
    else if (flag == 81)
        fprintf(stderr, "L%d: can't div, stack too short\n", L);
    else if (flag == 82)
        fprintf(stderr, "L%d: division by zero\n", L);
    else if (flag == 9)
        fprintf(stderr, "L%d: can't mul, stack too short\n", L);

	else if (flag == 10)
		fprintf(stderr, "L%d: unknown instruction %s\n", L, cmd);
	else if (flag == 11)
		fprintf(stderr, "Error: malloc failed\n");

	if (head != NULL)
		free_dlistint(head);
	free_grid(lines);
	exit(EXIT_FAILURE);
}
