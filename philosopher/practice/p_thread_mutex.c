/*
 mutex는 MUTual EXclusion의 약자로 상호배제라 한다.
 공유하는 데이터 영역을 보호하기 위해서 사용한다.
 뮤텍스는 lock과 unlock 두개의 행동만이 정의되어 있다.
 lock을 통해서 임계영역을 진입하고 unlock을 통해서 임계영역을 빠져나오고
 다른 스레드가 임계영역에 들어갈 수 있게 한다.
 int pthread_mutex_lock(pthread_mutex_t *mutex);
 int pthread_mutex_unlock(pthread_mutex_t *mutex);
 int phtread_mutex_destroy(pthread_mutex_t *mutex);
 int phtread_mutex_init(phtread_mutex_t *mutex, const phtread_mutex_attr *attr);
 phtread_mutex_init은 항상 0을 리턴하고 나머지 함수들은 성공시 0 실패시 0이 아닌
 숫자를 반환하고 errno를 설정한다.
 뮤텍스는 fast, recurisev, error checking 3가지 종류중 하나를 선택할 수 있으며
 기본적으로는 fast가 사용된다.
 뮤텍스를 사용하기전에 초기화를 해주어야 하는데 두가지 방법이 있다.
 PHTREAD_MUTEX_INITIALIZER 상수를 이용해서 초기화 해주는 방법
 pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 이런식
 init 함수를 사용해 동적할당 하여 초기화 하는 방법이 있다.
 보통 후자를 많이 사용한다.
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	cnt;
pthread_mutex_t mutex;

void	*count(void *arg)
{
	int		i;
	char	*name;

	i = 0;
	name = (char *)arg;
	pthread_mutex_lock(&mutex);
	cnt = 0;
	while (i < 10)
	{
		printf("%s cnt : %d \n", name, cnt);
		cnt++;
		i++;
		usleep(1);
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(void)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&thread1, NULL, count, (void *)"thread1");
	pthread_create(&thread2, NULL, count, (void *)"thread2");
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&mutex);
}
