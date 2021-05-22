#include "minishell.h"

static int	is_space(int c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int	main(void)
{
	int i = 0;
	char	str[5] = "   44";

	while (is_space(str[i++]))

	printf("%d\n", i);
}
