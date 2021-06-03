#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		i -= 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void		ft_echo(char **str)
{
	int i;
	int	j;

	if (ft_strcmp("echo", str[1]) == 0)
	{
		if (str[2] == NULL)
		{
			printf("\n");
			return ;
		}
		i = 2;
		if (ft_strncmp("-n", str[i], 2) == 0)
		{
			while (ft_strncmp("-n", str[i], 2) == 0)
			{
				j = 2;
				while (str[i][j])
				{
					if (str[i][j] == 'n')
						j++;
					else
					{
						if (i == 2)
							printf("%s\n", str[i]);
						else
							printf("%s", str[i]);
						return ;
					}
				}
				i++;
				if (str[i] == NULL)
					return ;
			}
			while (str[i])
			{
				printf("%s", str[i]);
				if (str[i + 1])
					printf(" ");
				i++;
			}
		}
		else
		{
			while (str[i])
			{
				printf("%s", str[i]);
				if (str[i + 1])
					printf(" ");
				i++;
			}
			printf("\n");
		}
	}
}

int	main(int argc, char *argv[])
{

	if (argc >= 2)
	{
		ft_echo(argv);
	}
}
