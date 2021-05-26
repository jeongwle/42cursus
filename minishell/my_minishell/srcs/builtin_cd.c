/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:33:49 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/26 16:27:24 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_mini *mini, char *path)
{
	char	*buf;
	int		res;

	buf = getcwd(NULL, 0);
	res = chdir(path);
	if (!res)
	{
		change_oldpwd_export(mini, buf);
		change_oldpwd_env(mini, buf);
		free(buf);
		buf = getcwd(NULL, 0);
		change_pwd(mini, buf);
	}
	free(buf);
}
