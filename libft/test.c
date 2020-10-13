#include "libft.h"
#include <stdio.h>

static int		word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (*(s + i) != c && *(s + i) != 0)
		count++;
	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			if (*(s + i + 1) == '\0')
				break ;
			if (*(s + i + 1) != c)
				count++;
		}
		i++;
	}
	return (count);
}

int	main(void)
{
	printf("%d \n", word_count("iab\0", 0));
}
