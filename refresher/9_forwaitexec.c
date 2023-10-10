#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - fork wait exec
 * Description: will create 5 pocesses and each is created on exit of last
 * Return: always zero
*/
int main(void)
{
	pid_t child_pid;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (int i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			printf("Child process number %d: pid=%d\n", i + 1, getpid());
			printf("father pid %d\n", getppid());
			execve("/bin/ls", args, NULL);

		} else
		{
			wait(NULL);
		}
	}
	return (0);
}
