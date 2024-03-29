/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:04:05 by mki               #+#    #+#             */
/*   Updated: 2021/06/16 12:55:12 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

int		syntax_error(int num)
{
	if (num == BACKSLASH_MULTI)
		printf("\\ Multiline Command doesn't work\n");
	else if (num == DQUOTES_MULTI)
		printf("\" Multiline Command doesn't work\n");
	else if (num == QUOTES_MULTI)
		printf("\' Multiline Command doesn't work\n");
	else if (num == PIPELINE_MULTI)
		printf("| Multiline Command doesn't work\n");
	else if (num == SYNTAX)
		printf("syntax error near unexpected token\n");
	return (1);
}
