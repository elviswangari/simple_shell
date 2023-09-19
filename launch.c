#include "main.h"
/**
 * launch - a function to read the buffer
 * 
 * @args: args to be executed
 * @background: the processes id running in the background
 * 
 * Return: returns 1 
**/
int launch(char *args[], int background) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("shell");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("shell");
    } else {
        if (!background) {
            do {
                pid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return (1);
}