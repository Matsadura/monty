#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;




typedef struct inst_s
{
        char *op;
        void (*f)(char *word, char *word2);
} inst_t;

void _push(char *s, char *s2);
void _pall(char *s, char *s2);

char *read_textfile(const char *filename, size_t letters);
void _parser(char *content, char **table);
void tokeniz(char **toks, char *L, char *d);
#endif /* MONTY */
