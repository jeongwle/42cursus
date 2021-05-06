#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	buf[4096];
	int		res;
	char	*changedir = "/Users/jeongwle/Documents/42cursus/42cursus/minishell";

	getcwd(buf, 100);
	printf("%s\n", buf);
	res = chdir("..");
	printf("%d\n", res);
	getcwd(buf, 100);
	printf("%s\n", buf);
}