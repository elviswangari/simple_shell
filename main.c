#include "main.h"
/**
 * main - program starts here
 * Return: zero always
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_buff;
	char *token;
	pid_t child_pid;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		read_buff = getline(&line, &len, stdin);

		if (read_buff == -1 || read_buff <= 0)
		{
			free(line);
			exit(-1);
		}

		token = strtok(line, " \t\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			return (-1);
		}
		if (child_pid == 0)
		{
			/* execute */
			char *args[] = {token, NULL};

			execve(args[0], args, NULL);

			perror("execve");
			_exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);

	return (0);
}
