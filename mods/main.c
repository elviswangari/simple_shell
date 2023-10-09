#include "main.h"
/**
 * main - a function to read the buffer
 *
 * Return: returns 0 on success
**/
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *tokens[MAX_TOKENS];
	int token_count;

	while (1)
	{
		read_line(input);
		token_count = split_line(input, tokens);

		if (token_count > 0)
		{
			execute(tokens);
		}
	}
	return (0);
}
