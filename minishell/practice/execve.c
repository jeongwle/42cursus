#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*str[3];

	str[0] = "/bin/ls";
	str[1] = "-a";
	str[2] = NULL;

	execve(str[0], str, NULL);
	printf("1\n");
}
