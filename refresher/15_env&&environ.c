#include <stdio.h>
/**
 * main - starts here
 * Return: zero always
*/
extern char **environ;

int main(int ac, char **av, char **env) {
    printf("Address of env parameter in main: %p\n", (void *)env);
    printf("Address of global variable environ: %p\n", (void *)environ);

    return (0);
}
