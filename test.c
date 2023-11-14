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
	char *table[1024];
	int i, j, line_number = 0;

	inst_t data[] = {
		{"push", _push},
		{"pall", _pall},
	};

	_parser(read_textfile(argv[1], 1024), table);

	for (i = 0; table[i]; i++)
	{
	    line_number++;
		for (j = 0; j < 2; j++)
		{
			if (strcmp(table[i], data[j].op) == 0)
				data[j].f(data[j].op, table[i]);
		}
	}

	return (0);
}
