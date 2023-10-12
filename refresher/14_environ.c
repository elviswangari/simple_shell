#include <stdio.h>
/**
 * main - starts here
 * Return: zero always
*/
extern char **environ;

int main(void) {
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return (0);
}
