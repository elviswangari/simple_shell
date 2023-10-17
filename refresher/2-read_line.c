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
	write(STDOUT_FILENO, "($) ", 4);
	read_buff = getline(&line, &len, stdin);

	if (read_buff == -1)
	{
		if (feof(stdin))
		{
			/* Handle end of file (Ctrl+D) */
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline failed");
			free(line);
			exit(EXIT_FAILURE);
		}
	}

	/* tockenize */
	token = strtok(line, "\t\n");
	return (token);
}
