#include "minishell.h"

int	main(int argc, char *argv[])
{
	int i;

	i = 0 ;
	if (argc == 2)
	{
		if (argv[1][i] == '+' || (argv[1][i] == '-'))
		{
			if (argv[1][i++] == '-')
				;
		}
	}
	printf("%d\n", i);
}
