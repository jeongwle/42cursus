/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:05:03 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/24 18:22:06 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(void)
{
	char	*res;

	res = getcwd(NULL, 0);
	delete_prev();
	write(1, res, ft_strlen(res));
	write(1, "\n", 1);
	write(1, "minishell > ", 12);
	free(res);
}
