#include "main.h"
/**
 * execute - executes commands
 * @token: the command to be executed
 */
void execute(char *token)
{
	pid_t child_pid;

	/* fork and execute */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *args[2];

		args[0] = token;
		args[1] = NULL;

		execve(args[0], args, NULL);

		/* execve failed, command not found */
		perror("");
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
