#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int	main(void)
{
	int	fd1, ret;
	char	messsage[32]={"STDERR from fd1\n"};

	fd1 = open("made_by_fd1", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);

	printf("file open\n");

	ret = dup2(fd1, STDOUT_FILENO);
	printf("fd1 : %d, ret: %d\n", fd1, ret);
}