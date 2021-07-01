#include <pthread.h> // int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
					 // 새로운 쓰레드를 생성한다. 새로운 쓰레드는 start_routine 함수를 아규먼트로 실행시키면서 생성된다. 생성된 쓰레드는
					 // pthread_exit을 호출하거나 start_routine에서 return 할 경우 제거된다. attr을 NULL로 할 경우 기본 특성으로 지정된다.
					 // 성공할 경우 thread에 쓰레드 식별번호를 저장하고 0을 리턴한다. 실패시 에러코드 값을 리턴	

#include <stdio.h>
#include <stdlib.h>

void	*test(void *data)
{
	int	i;
	int	a;

	i = 0;
	a = *(int *)data;
	while (i < 10)
	{
		printf("%d\n", i*a);
		i++;
	}
	void	*res;
	res = (i * 100);
	return (res);
}

int	main(void)
{
	int	a;
	pthread_t thread_t;
	int status;
	int	res;

	a = 100;
	if ((res = pthread_create(&thread_t, NULL, test, (void *)&a)) < 0)
	{
		perror("thread crate error:");
		exit(0);
	}
	printf("res = %d\n", res);
	pthread_join(thread_t, (void **)&status);
	printf("Thread End %d\n", status);
	return (0);
}


// int pthread_join(pthread_t th, void **thread_return);
// pthread_join은 실별번호 th로 시작된 쓰레드가 종료되는걸 기다린다. 이러한 쓰레드의 종료는 pthread_exit으로 종료되거나
// 혹은 리턴되는 경우 발생한다.
// 만약 thread_return값이 NULL이 아니라면, th의 리턴 값이 저장된 영역이 전달되게 된다. 스레드가 조인되기 위해서는 
// joinalbe상태의 스레드로 작동하고 있어야 한다. 만약 스레드가 pthread_detach 함수를 통해서 detached 상태가 되거나
// pthread_create로 실행될 때 PTHREAD_CREATE_DETACHED특성으로 실행되었다면 join으로 기다릴 수 없게 된다.
// joinable 스레드가 종료되더라도 메모리자원 등이 즉시 해제되는 것이 아니다. pthread_join 함수를 만나야지만 해제된다.
// 그러므로 모든 joinable 스레드에 대해서는 반드시 pthread_join을 호출해주어야 한다. 그렇지 않을 경우 메모리 누수가 발생할 것이다.
// 성공시 스레드에 스레드 식별번호를 저정하고 0을 리턴, 실패할 경우 0이 아닌 에러코드 값을 리턴한다.
