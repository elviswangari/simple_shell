#include "main.h"
/**
 * display_prompt - function to display
 */
void display_prompt(void)
{
	char *cwd = getcwd(NULL, 0);

	if (cwd != NULL)
	{
		printf("#cisfun:%s$ ", cwd);
		free(cwd);
	}
	else
	{
		perror("getcwd");
	}
}
