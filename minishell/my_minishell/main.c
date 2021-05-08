/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:16:04 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/08 17:39:02 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	long long int	compare;
	char			buf[4096];
	int				idx;

	argc = 0;
	argv = 0;
	idx = 0;
	compare = 0;
	term_set();
	while (read(0, &compare, 4) > 0)
	{
		if (compare == BACKSPACE)
		{
			delete_end();
		}
		else if (compare == ARROWUP || compare == ARROWDOWN)
		{
		}
		else
		{
			write(1, &compare, 1);
		}
		buf[idx] = compare;
		idx++;
		compare = 0;
	}
}