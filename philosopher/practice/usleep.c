#include <unistd.h> // usleep header /  return value : success = 0 fail = - 1 / 지정한 micro초 동안 대기 100만분의 1
					// int usleep(useconds_t usec);
#include <stdio.h>

int	main(void)
{
	while (1)
	{
		printf("1초마다 출력됩니다\n");
		usleep(1000 * 1000);
	}
}
