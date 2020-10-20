#include <stdio.h>

void	Func(void)
{
	static int	x;

	x = 0;
	x++;
	printf("%d \n", x);
}

int	main(void)
{
	Func();
	Func();
	Func();
	Func();
	Func();

	return (0);
}
