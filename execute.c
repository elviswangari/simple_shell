#include "main.h"
/**
 * execute - a function to execute a partcular command
 * @args: an array of exec commands
 * Return: returns a function
**/
int execute(char *args[])
{
	int background = 0;
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	} else if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "shell: expected argument to 'cd'\n");
		} else
		{
			if (chdir(args[1]) != 0)
			{
				perror("shell");
			}
		}
		return (1);
	}
	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], "&") == 0)
		{
			background = 1;
			args[i] = NULL;
			break;
		}
	}
	return (launch(args, background));
}
