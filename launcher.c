#include "monty.h"

void _launcher(char *lines[][3])
{
	int i, j;
	unsigned int line_number = 0;

	stack_t *new_node;
	instruction_t data[] = {
		{"push", _push},
		{"pall", _pall},
	};

	for (i = 0; lines[i][0]; i++)
	{
		line_number++;
		if (is_comment(lines[i][0]))
			continue;

		/*printf("[%d][%s] <==> ", line_number, lines[i][0]);*/
		for (j = 0; j < 2; j++)
		{
			if (strcmp(lines[i][0], data[j].opcode) == 0)
			{
				if (lines[i][1])
				{
					new_node = create_node(lines[i][1]);
					data[j].f(&new_node, line_number);
					free(new_node);
				}
				else
					data[j].f(&head, line_number);
			}
		}
	}
}
