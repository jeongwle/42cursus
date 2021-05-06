#include "minishell.h"

int	main(void)
{
	char	*buf;
	int		read_val;
	char	**some;

	while ((read_val = read(0, buf, 4096)))
	{
		buf[read_val] = 0;
		some = ft_split(buf, ' ');
		write(1, "$>", 2);
		printf("%s", buf);
	}
	return (0);
}