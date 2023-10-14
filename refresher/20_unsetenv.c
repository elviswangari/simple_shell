#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

/**
 * _unsetenv - deletes the variable name from the environment
 * @name: the name of the environment variable to delete
 * Description: This function removes a variable from the
 * 		environment by shifting elements
 * 		in the environ array.
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	if (name == NULL)
	{
		return (-1);
	}

	// Find the position of the variable in the environment
	int position = -1;
	for (int i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			position = i;
			break;
		}
	}

	if (position == -1)
	{
		// Variable not found
		return (0);
	}

	// Free the memory occupied by the variable
	free(environ[position]);

	// Shift elements to remove the gap created by freeing memory
	for (int i = position; environ[i] != NULL; i++)
	{
		environ[i] = environ[i + 1];
	}

	return (0);
}

int main(void)
{
	// Set an environment variable
	setenv("MY_VARIABLE", "123", 1);

	// Print the value of the environment variable
	printf("Before _unsetenv: %s\n", getenv("MY_VARIABLE"));

	// Unset the environment variable using _unsetenv
	_unsetenv("MY_VARIABLE");

	// Print the value after unsetting
	printf("After _unsetenv: %s\n", getenv("MY_VARIABLE"));

	return (0);
}
