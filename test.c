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
	char *lines[1024];
	char *cmd[1024];
	int i, j, line_number = 0;

	inst_t data[] = {
		{"push", _push},
		{"pall", _pall},
	};

	if (argc < 2 || argc > 2)
		{
			printf("argc err\n");
			exit(1);
		}
	/* at some point check if alwase the line ends with \n*/

	/* tokenize the input and clean it */
	input = read_textfile(argv[1], 1024); /* i put this here cuz it needs to be freed */
	cmd_list(lines, input, "\n");

	for (i = 0; lines[i]; i++)
	{
		/* tokenize one line per loop*/
		tokeniz(cmd, lines[i], " ");
	    line_number++;
		for (j = 0; j < 2; j++)
		{
			if (strcmp(cmd[0], data[j].op) == 0)
				data[j].f(data[j].op, cmd[1]);
		}
		free_grid(cmd);
	}

	free_grid(lines);
	free(input);

	return (0);
}
