#include "monty.h"


void _pchar(stack_t **stack, unsigned int line_number)
{
    (void) stack; /**stack is not used in this function **/
	(void) line_number;

    putchar(head->n);
    putchar('\n');
}

void _pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = head;
    (void) stack; /**stack is not used in this function **/
	(void) line_number;
    
    while (tmp && tmp->n != 0 && (tmp->n < 126 && tmp->n > 32))
    {
        putchar(tmp->n);
        tmp = tmp->next;
    }
    putchar('\n');
}