#include "main.h"
/**
 * read_line - a function to read the buffer
 *
 * @buffer: the input from the user
 *
 * Return: returns void
**/
void read_line(char *buffer)
{
	printf("shell> ");
	fgets(buffer, MAX_INPUT_SIZE, stdin);
	strtok(buffer, "\n");
}


