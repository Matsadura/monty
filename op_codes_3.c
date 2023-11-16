#include "monty.h"


void _pchar(stack_t **stack, unsigned int line_number)
{
    (void) stack; /**stack is not used in this function **/
	(void) line_number;

    putchar(head->n);
}