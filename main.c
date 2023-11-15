#include "monty.h"

stack_t *head = NULL;

int main(int argc, char **argv)
{
	char *input;
	char *lines[MAX_LINES][MAX_TOKS];

	if (argc < 2 || argc > 2)
	{
		printf("argc err\n");
		exit(1);
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
