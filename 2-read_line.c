#include "main.h"
/**
 * read_line - gets and splits the line
 * Return: line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_buff;
	char *token;

	/* prompt and read line */
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	read_buff = getline(&line, &len, stdin);

	if (read_buff == 0)
	{
		/* Handle end of file (Ctrl+D) */
		exit(EXIT_SUCCESS);
	}
	else if (read_buff == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}

	/* tockenize */
	token = strtok(line, "\t\n");
	return (token);
}
