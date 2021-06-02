/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:05:03 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/25 20:39:21 by jeongwle         ###   ########.fr       */
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
	free(res);
}
