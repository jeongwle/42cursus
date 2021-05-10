#include <stdio.h>

void	practice(int *idx, char *buf)
{
	buf[*idx] = '4';
	(*idx)--;
}

int	main(void)
{
	char	buf[4096];
	int		idx;

	buf[0] = '1';
	buf[1] = '2';
	buf[2] = '3';
	buf[4] = 0;
	idx = 3;
	buf[idx] = '5';;
	printf("buf = %s idx = %d\n", buf, idx);
	practice(&idx, buf);
	printf("buf = %s idx = %d\n", buf, idx);
	while(1)
		;
}