#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64 

void read_line(char *buffer);
int split_line(char *line, char *tokens[]);
int launch(char *args[], int background); 
int execute(char *args[]);

#endif /* MAIN_H */
