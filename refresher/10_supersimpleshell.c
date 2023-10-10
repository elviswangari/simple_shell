#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

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
		/*read line*/
		printf("#cisfun$ ");
		read_buff = getline(&line, &len, stdin);

		if (read_buff <= 0)
		{
			return (-1);
		}
		// printf("%s", line);
		/* split line */
		token = strtok(line, " \t\n");
		// while (token != NULL)
		// {
		// 	// printf("%s\n", token);
		// 	token = strtok(NULL, " \t\n");
		// }
		/* fork */
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
			// printf("Child process: PID=%d\n", getpid());
			execve(args[0], args, NULL);
			
			perror("execve");
			_exit(EXIT_FAILURE);
		} else
		{
			/* execute */
			// printf("Parent process: PID=%d, Child PID=%d\n", getpid(), child_pid);
			/* wait */
			wait(NULL);
		}
	}
	free(line);
	return (0);
}
