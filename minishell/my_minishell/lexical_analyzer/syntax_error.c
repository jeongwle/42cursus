/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:04:05 by mki               #+#    #+#             */
/*   Updated: 2021/05/20 12:58:42 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		syntax_error(int num)
{
	if (num == ERROR_BACKSLASH)
		printf("\\ Multiline Command doesn't work\n");
	else if (num == ERROR_DQUOTES)
		printf("Multiline Command doesn't work\n");
	else if (num == ERROR_QUOTES)
		printf("Multiline Command doesn't work\n");
	else if (num == ERROR_PIPELINE)
		printf("Multiline Command doesn't work\n");
	else if (num == ERROR_ENV)
		printf("wrong $\n");
	else if (num == ERROR_SEMICOLON)
		printf("bash: syntax error near unexpected token `;'\n");
	else if (num == ERROR_SEMICOLONS)
		printf("bash: syntax error near unexpected token `;;'\n");
	return (1);
}