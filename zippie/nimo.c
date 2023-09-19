#include "nimo.h"
void read_line(char *buffer)
{
    printf("shell> ");
    fgets(buffer, MAX_INPUT_SIZE, stdin);
    
    char *token = strtok(buffer, " \t\n");
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, " \t\n");
    }
}

int main()
{
    char input[MAX_INPUT_SIZE];

    read_line(input);

    return 0;
}