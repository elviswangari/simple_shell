#include <stdio.h>
#include <stdlib.h>
/**
 * main - program starts here
 * Return: zero on success
*/
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	size_t read;
	
	printf("$ ");
	read = getline(&line, &len, stdin);

	if (read <= 0)
	{
		return (-1);
	}

	printf("%s \n", line);
	printf("characters read by getline %lu\n", read);

	return (0);
}
