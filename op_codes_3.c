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

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = head, *current;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	if (head == NULL || head->next == NULL)
		return;

	head = head->next;
	head->prev = NULL;

	current = head;
	while (current->next)
		current = current->next;

	current->next = tmp;
	tmp->next = NULL;
	tmp->prev = current;
}

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *current = head;
	(void) stack; /**stack is not used in this function **/
	(void) line_number;

	if (head == NULL || head->next == NULL)
		return;

	while (current->next)
		current = current->next;

	tmp = current;
	current = current->prev;

	current->next = NULL;

	tmp->next = head;
	tmp->prev = NULL;
	head->prev = tmp;

	head = head->prev;
}

void _push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *cur = head;
	(void) line_number;
	
	/** head is the global variable for the stack or queue*/
	add_nodeint_queue(&head, (*stack)->n); /**stack->n is the value of the new node*/
	free(tmp);
}