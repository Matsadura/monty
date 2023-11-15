#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>

/* list of marcos */

#define MAX_BUF 1024
#define MAX_LINES 1024
#define MAX_TOKS 3 /* cuz we only need two token and the 3 tok is a NULL*/
#define NEW_LINE "\n"
#define SPACE " "

/* 3D array for the commands*/
/*extern char *lines[MAX_LINES][MAX_TOKS];*/
/*extern stack_t *stack;*/

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

void _launcher(char *lines[][3]);

void _push(char *s, char *s2);
void _pall(char *s, char *s2);

char *read_textfile(const char *filename, size_t letters);
void tokeniz(char **toks, char *L, char *d);
char *_liner(char *str);
void cmd_list(char *input, char *lines[][3]);
int is_comment(char *line);

void free_grid(char *grid[][3]);
#endif /* MONTY */
