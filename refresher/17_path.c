#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
/**
 * main - program starts here
 * Return: zero always
*/
int main(void)
{
	const char *path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable is not set.\n");
		return (EXIT_FAILURE);
	}

	char *pathCopy = strdup(path);

	if (pathCopy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(pathCopy, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}

	free(pathCopy);
	return (0);
}
