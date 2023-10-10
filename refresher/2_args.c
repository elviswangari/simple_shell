#include <stdio.h>
/**
 * main - printing arguments from prompt
 * @ac: arguments count
 * @av: pointer to an array of string
 * Return: always zero
*/
int main(int ac __attribute__((unused)), char **av)
{
	for (int i = 1; av[i] != NULL; i++)
	{
		printf("%s ", av[i]);
	}

	printf("\n");
	return (0);
}
