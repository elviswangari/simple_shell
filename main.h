#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int test_betty(void);
char *read_line(void);
void execute(char *command);

#endif /*MAIN_H*/
