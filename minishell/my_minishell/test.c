#include <stdio.h>
#include "./libft/libft.h"

void	ft_free(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

int	main(void)
{
	char	*buf;

	while (1)
	{
		;
//		buf = ft_strdup("1");
//		printf("%s\n", buf);
//		ft_free(&buf);
//		printf("%s\n", buf);
	}
}