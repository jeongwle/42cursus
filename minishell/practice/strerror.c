#include <string.h>
#include <stdio.h>
#include <errno.h>

int	main(void)
{
	FILE	*fp;

	fp = fopen("unexist.ent", "r");
	if (fp == NULL)
		printf("%s\n", strerror(errno));
	return (0);
}