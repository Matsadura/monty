#include "monty.h"

void _launcher(void)
{
	int i, j, line_number = 0;

	inst_t data[] = {
		{"push", _push},
		{"pall", _pall},
	};

	for (i = 0; lines[i][0]; i++)
	{
		line_number++;
		if (is_comment(lines[i][0]))
			continue;

		printf("[%d][%s] <==> ", line_number, lines[i][0]);
		for (j = 0; j < 2; j++)
		{
			if (strcmp(lines[i][0], data[j].op) == 0)
				data[j].f(data[j].op, lines[i][1]);
		}
	}
}
