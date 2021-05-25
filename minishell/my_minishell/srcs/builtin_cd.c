/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:33:49 by jeongwle          #+#    #+#             */
/*   Updated: 2021/05/25 21:23:13 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_oldpwd(t_mini *mini)
{
 //getcwd로 현재 디렉토리 경로 받아서 pwd랑 oldpwd 재설정 하거라! 그리고 - 도 돌아가게끔 할것 그게 네 할일
}

void	cd(t_mini *mini, char *path)
{
	int	res;

	res = chdir(path);
	if (!res)
		change_oldpwd(mini)
}
