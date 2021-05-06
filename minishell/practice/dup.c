#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	int	fd1, fd2;
	char	message[32] = {"message via fd2\n"};

	fd1 = open("made_by_fd1", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
	fd2 = dup(fd1);
	write(fd2, message, strlen(message));
	printf("fd1 : %d, fd2: %d\n", fd1, fd2);
	close(fd1);
	close(fd2);
	return (0);
}