#include "minishell.h"

void	echo_n_opt(int *i, char **str)
{
	int	j;

	while (str[*i])
	{
		if (!ft_strncmp("-n", str[*i], 2))
		{
			j = 2;
			while (str[*i][j])
			{
				if (str[*i][j] == 'n')
					j++;
				else
				{

				}
			}
		}
	}
}

void	ft_echo(char **str)
{
	int	i;

	if (str[1] == NULL)
	{
		printf("\n");
		return ;
	}
	i = 1;
	if (!ft_strncmp("-n", str[i], 2))
		echo_n_opt(&i, str);
}
