#include "main.h"
/**
 * read_input - program starts here
 * Return: the line
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_buff;

	read_buff = getline(&line, &len, stdin);

	if (read_buff == -1 || read_buff <= 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	/* Remove newline character */
	line[strcspn(line, "\n")] = '\0';

	return (line);
}
