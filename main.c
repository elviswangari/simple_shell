#include "main.h"
/**
 * main - program starts here
 * Return: zero always
 */
int main(void)
{
	while (1)
	{
		char *line = read_input();
		char *token = strtok(line, " \t\n");

		display_prompt();

		/**
		 * if (strcmp(line, "exit") == 0 || strcmp(line, "quit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		*/

		if (token != NULL)
		{
			execute_command(token);
		}

		free(line);
	}

	return (EXIT_SUCCESS);
}
