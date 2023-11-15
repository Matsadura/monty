#include "monty.h"
char *lines[MAX_LINES][MAX_TOKS];

void _push(char *s, char *s2)
{
	printf("OPcode :%s, argument : %s\n", s, s2);
}

void _pall(char *s, char *s2)
{
	printf("OPcode :%s, argument : %s\n", s, s2);
}



/*void _parser(char *content, char **table)
{
	char *lines[1024];
	int i;

	tokeniz(lines, content, "\n");
	for (i = 0; lines[i]; i++)
	{
		tokeniz(table, lines[i], " ");
	}

}*/

void tokeniz(char **toks, char *L, char *d)
{
	char *tmp;
	int i;

	tmp = strtok(L, d);
	for (i = 0; tmp && i < 2; i++)
	{
		toks[i] = strdup(tmp);
		tmp = strtok(NULL, d);
	}

	toks[i] = NULL;
}

int is_comment(char *line)
{
	/* check for comment*/
	if (line[0] == '#')
		return (1); /* if the line is a comment */

	return (0);	/* if not */
}

void cmd_list(char *input)
{
	char *buf[MAX_LINES];
	char *tmp;
	int i = 0;

	/* in this step the input will be parsed line by line */
	tmp = strtok(input, NEW_LINE);
	while (tmp)
	{
		buf[i++] = _liner(tmp);
		tmp = strtok(NULL, NEW_LINE);
	}
	buf[i] = NULL;

	/* in this step the parsed line will parsed to tokens
		and we'll stor them in *lines[][3] */
	for (i = 0; buf[i]; i++)
	{
		tokeniz(lines[i], buf[i], SPACE);
		free(buf[i]);
	}
	lines[i][0] = NULL;

	free(input); /* free the input "the content" */
}

/**
 * _liner - removes whitespaces
 * @str: the str to handle
 * Return: the clean str
 */

char *_liner(char *str)
{
	char BUF[1024];
	int i = 0, k = 0;

	if (str != NULL)
	{
		while (str[i] == ' ')
			i++;

		for (; str[i]; i++)
		{
			if (str[i] != ' ')
				BUF[k++] = str[i];
			else if (str[i] == ' ' && str[i - 1] != ' ')
				BUF[k++] = str[i];
		}
	}
	if (BUF[k - 1] == ' ')
		BUF[k - 1] = '\0';
	else
		BUF[k] = '\0';

	return (strdup(BUF));
}