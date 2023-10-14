#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **my_environ;

/**
 * _setenv - changes or adds an environment variable
 * @name: the name of the environment variable
 * @value: the value to set for the environment variable
 * @overwrite: flag to determine whether to overwrite the variable if it exists
 * Description: a clone of the setenv function
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		return -1;
	}

	// Check if the environment variable already exists
	for (int i = 0; my_environ[i] != NULL; i++)
	{
		if (strstr(my_environ[i], name) == my_environ[i])
		{
			if (!overwrite)
			{
				// Variable exists, and overwrite is disabled
				return 0;
			}

			// Overwrite the existing variable
			free(my_environ[i]);
			my_environ[i] = malloc(strlen(name) + strlen(value) + 2);
			if (my_environ[i] == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}

			sprintf(my_environ[i], "%s=%s", name, value);
			return 0;
		}
	}

	// If the variable does not exist, add it to the environment
	size_t count = 0;
	while (my_environ[count] != NULL)
	{
		count++;
	}

	// Allocate space for the new variable
	char *new_variable = malloc(strlen(name) + strlen(value) + 2);
	if (new_variable == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	sprintf(new_variable, "%s=%s", name, value);

	// Resize the environment array
	my_environ = realloc(my_environ, sizeof(char *) * (count + 2));
	if (my_environ == NULL)
	{
		perror("Memory allocation error");
		free(new_variable);
		exit(EXIT_FAILURE);
	}

	// Add the new variable
	my_environ[count] = new_variable;
	my_environ[count + 1] = NULL;

	return 0;
}

/**
 * main - starts here
 * Return: always zero
 */
int main(void)
{
	// Initialize a custom environment array
	my_environ = malloc(sizeof(char *));
	if (my_environ == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	my_environ[0] = NULL;

	_setenv("MY_VARIABLE", "123", 1);

	for (int i = 0; my_environ[i] != NULL; i++)
	{
		printf("%s\n", my_environ[i]);
	}

	// Free the custom environment array
	for (int i = 0; my_environ[i] != NULL; i++)
	{
		free(my_environ[i]);
	}
	free(my_environ);

	return 0;
}
