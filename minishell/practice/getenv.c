#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <termcap.h>

int	main(void)
{
	char *env;
	char bp[1024];
	int a;

	env = getenv("TERM");
	printf("%s\n", env);
	a = tgetent(bp, "xterm");
	printf("%s\n", bp);
}