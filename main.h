#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int test_betty(void);
void display_prompt(void);
char *read_input(void);
void execute_command(char *command);

#endif /*MAIN_H*/
