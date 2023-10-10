#include <stdio.h>
#include <unistd.h>
/**
 * main - getting the pid and the ppid
 * Return: zero always
*/
int main(void)
{
	pid_t my_pid, my_ppid;

	my_pid = getpid();
	my_ppid = getppid();

	printf("parent pid is %u\n", my_ppid);
	printf("child pid is %u\n", my_pid);

	return (0);
}
