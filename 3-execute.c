#include "main.h"
/**
 * execute_command - program starts here
 * @command: the command to be executed
 */
void execute_command(char *command)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		char **args = malloc(2 * sizeof(char *));

		if (args == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}

		args[0] = command;
		args[1] = NULL;

		execve(args[0], args, NULL);
		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
