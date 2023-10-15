#include "main.h"
/**
 * read_line - gets and splits the line
 * Return: line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	int i;
	ssize_t read_buff;
	char *token;

	/* prompt and read line */
	printf("#cisfun$ ");
	read_buff = getline(&line, &len, stdin);

	if (read_buff == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}

	/* tockenize */
	for (i = 0; i < 2; i++)
	{
		token = strtok(line, " \t\n");
	}
	printf("%s", token);
	return (token);
}
