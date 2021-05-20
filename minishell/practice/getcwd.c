#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	*buf;
	pid_t	pid;

	pid = fork();
	buf = getcwd(NULL, 0);
	if (pid == 0)
		printf("%s\n", buf);
	else
	{
		if ((getcwd(buf, 20)) == NULL)
			printf("Error\n");
	}
	return (0);
}
