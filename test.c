#include "monty.h"

/*int main(int argc, char **argv)
{
	char *table[1024];
	int i;

	inst_t data[] = {
		{"push", _push},
		{"pall", _pall},
	};

	_parser(read_file(argv[1], 1024), table);


	for (i = 0; table[line_number]; line_number++ )
	{
		for (i = 0; i < 2; i++)
		{
			if (strcmp(content, data[i].op) == 0)
				data[i].f(data[i].op);
		}
	}

	free(content);
	return (0);
}*/

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
	return (0);
}
