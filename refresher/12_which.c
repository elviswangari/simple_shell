#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
/**
 * main - program starts here
 * @argc: argument count
 * @argv: argument vector
 * Return: always zero on sucess
*/
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s file1 file2 ...\n", argv[0]);
		return (EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++)
	{
		const char *filename = argv[i];
		struct stat fileStat;

		if (stat(filename, &fileStat) == 0)
		{
			printf("Information for: %s\n", filename);
			printf("File Size: %ld bytes\n", fileStat.st_size);
			printf("Number of Links: %ld \n", fileStat.st_nlink);
			printf("File inode: %ld\n", fileStat.st_ino);
		} else
		{
			perror("Error getting file information");
		}
		printf("\n");
	}
	return (EXIT_SUCCESS);
}
