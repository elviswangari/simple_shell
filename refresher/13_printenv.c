#include <stdio.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i = 0;

//     i = 0;
    while (env[i] != NULL)
    {
	printf("Number %u \t", i);
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}