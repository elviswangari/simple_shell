#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;
/**
 * _getenv - gets environment variable
 * @name: the environment variable
 * Return: always zero
*/
char *_getenv(const char *name)
{
    if (name == NULL)
    {
        return NULL;
    }

    for (int i = 0; environ[i] != NULL; i++)
    {
        const char *variable = environ[i];
        const char *equal_sign = strchr(variable, '=');

        if (equal_sign != NULL)
        {
            size_t name_length = equal_sign - variable;
            if (strncmp(variable, name, name_length) == 0)
            {
                return strdup(equal_sign + 1);
            }
        }
    }

    return NULL;
}

/**
 * main - program starts here
 * Return: always zero
*/
int main(void)
{
	char *homeDir = _getenv("HOME");
	char *homeDir1 = getenv("HOME");

	if (homeDir != NULL && homeDir1 != NULL)
	{
		printf("Home directory _getenv: %s\n", homeDir);
		printf("Home directory getenv: %s\n", homeDir1);
	} else
	{
		printf("HOME environment variable not set\n");
	}
	return (0);
}
