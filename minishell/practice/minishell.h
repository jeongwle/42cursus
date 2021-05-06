#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);

#endif