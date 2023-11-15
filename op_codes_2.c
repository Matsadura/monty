#include "monty.h"

void _add(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = head;
    (void) stack; /**stack is not used in this function **/
	(void) line_number;

    (head->next)->n = head->n + (head->next)->n;
    head = head->next;
    free(tmp);
}

void _sub(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = head;
    (void) stack; /**stack is not used in this function **/
	(void) line_number;

    (head->next)->n = (head->next)->n - head->n;
    head = head->next;
    free(tmp);
}

void _div(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = head;
    (void) stack; /**stack is not used in this function **/
	(void) line_number;

    (head->next)->n = (head->next)->n / head->n;
    head = head->next;
    free(tmp);
}

void _mul(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = head;
    (void) stack; /**stack is not used in this function **/
	(void) line_number;

    (head->next)->n = (head->next)->n * head->n;
    head = head->next;
    free(tmp);
}