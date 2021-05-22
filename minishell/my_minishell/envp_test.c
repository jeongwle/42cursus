#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	int i;

	i = 0;
	argc = 0;
	argv = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
