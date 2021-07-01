#include <sys/time.h> // gettimeofday header return value : success = 0 fail = -1
#include <stdio.h>

int	main(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, NULL);
	printf("%ld\n %d\n", mytime.tv_sec, mytime.tv_usec); // tv_sec 은 1970년 1월 1일을 기준으로 흐른 시간을 초로 tv_usec은 마이크로초 백만분의 일
	//struct timezone 구조체는 더 이상 사용되지 않고 지원도 되지 않기 때문에 NULL을 넣어준다
	return (0);
}
