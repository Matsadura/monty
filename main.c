#include "monty.h"

stack_t *head = NULL;

/**
 * main - an interpreter for the Monty bytecode
 * @argc: number of arguments
 * @argv: the arguments
 * Return: EXIT_SUCCESS or Failure
 */

int main(int argc, char **argv)
{
	char *input;
	char *lines[MAX_LINES][MAX_TOKS];

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* i put this here cuz it needs to be freed "cmd_list" */
	input = read_textfile(argv[1], MAX_BUF);

	/* tokenize the input and clean it */
	cmd_list(input, lines);

	/* lunch*/
	_launcher(lines);

	free_grid(lines);
	free_dlistint(head);
	return (0);
}
