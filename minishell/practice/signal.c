#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i;

	i = 0;
	signal(SIGINT, SIG_DFL);
	while (++i)
	{
		printf("%d\n", i);
		sleep(1);
	}
	return (0);
}