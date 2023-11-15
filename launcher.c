#include "monty.h"

void test(void);
/**
 * _launcher - executes the OPcode
 * @lines: the parser instructions
 */
void _launcher(char *lines[][3])
{
	int i, j;
	unsigned int line_number = 0;
	stack_t *new_node;
	instruction_t data[] = {
		{"pall", _pall},
	};

	for (i = 0; lines[i][0]; i++)
	{
		line_number++;
		if (is_comment(lines[i][0]))
			continue;
		/*printf("[%d][%s] <==> ", line_number, lines[i][0]);*/
		for (j = 0; j < 1; j++)
		{
			if (strcmp(lines[i][0], "push") == 0)
			{
				if (lines[i][1] && isInteger(lines[i][1]) == 0)
				{


					new_node = create_node(lines[i][1]);
					_push(&new_node, line_number);
					free(new_node);
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free_dlistint(head);
					free_grid(lines);
					exit(EXIT_FAILURE);
				}
				break;
			}
			else if (strcmp(lines[i][0], data[j].opcode) == 0)
			{
				data[j].f(&head, line_number);
				break;
			}
		}
		if (j == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, lines[i][0]);
			/**possible free_list*/
			free_dlistint(head);
			free_grid(lines);
			exit(EXIT_FAILURE);
		}
	}
}
