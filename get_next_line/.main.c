#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	char *line;
	int i;

   	fd = open( "./test.txt", O_RDONLY );
	i = get_next_line(fd, &line);
	printf("%d \n", i);
	printf("%s \n", line);
	i = get_next_line(fd, &line);
	printf("%d \n", i);
	printf("%s \n", line);
	i = get_next_line(fd, &line);
	printf("%d \n", i);
	printf("%s \n", line);
	i = get_next_line(fd, &line);
	printf("%d \n", i);
	printf("%s \n", line);
	i = get_next_line(fd, &line);
	printf("%d \n", i);
	printf("%s \n", line);
}
