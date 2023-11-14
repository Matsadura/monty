#include "monty.h"

void _push(char *s, char *s2)
{
	printf("OPcode :%s, argument : %s\n", s, s2);
}

void _pall(char *s, char *s2)
{
	printf("OPcode :%s, argument : %s\n", s, s2);
}



void _parser(char *content, char **table)
{
	char *lines[1024];
	int i;

	tokeniz(lines, content, "\n");
	for (i = 0; lines[i]; i++)
	{
		tokeniz(table, lines[i], " ");
	}

}

void tokeniz(char **toks, char *L, char *d)
{
	char *tmp;
	int i;

	tmp = strtok(L, d);
	for (i = 0; tmp; i++)
	{
		toks[i] = strdup(tmp);
		tmp = strtok(NULL, d);
	}

	toks[i] = NULL;
}
