#include "monty.h"

/**
 * _push - adds a node to the stack or queue
 * @stack: the node
 * @line_number: the line number of the instruction
 */
void _push(stack_t **stack, unsigned int line_number)
{
	/** head is the global variable for the stack or queue*/
	add_dnodeint(&head, (*stack)->n); /**stack->n is the value of the new node*/
	printf("PUSH & line_number is %d\n", line_number);
}

/**
 * _pall - prints the stack or queue
 * @stack: the node
 * @line_number: the line number of the instruction
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void) stack; /**stack is not used in this function **/

	print_dlistint(head); /** head is the stack or queue*/
	printf("PALL & Line_number is %d\n", line_number);
}
