#include "main.h"
/**
 * main - program starts here
 * Return: zero always
 */
int main(void)
{
	while (1)
	{
		char *line = read_line();
		
		if (line == NULL)
		{
			continue;
		}

		execute(line);
	}
	return (0);
}
