/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_multiline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:48:52 by mki               #+#    #+#             */
/*   Updated: 2021/06/15 21:30:27 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	quote(char *str, int *i)
{
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '\'')
			return (0);
		(*i)++;
	}
	if (str[*i] == 0)
		return (syntax_error(QUOTES_MULTI));
	return (0);
}

int	dquote(char *str, int *i)
{
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == '\"')
			return (0);
		if (str[*i] == '\\' && str[*i + 1] != 0)
			(*i)++;
		(*i)++;
	}
	if (str[*i] == 0)
		return (syntax_error(DQUOTES_MULTI));
	return (0);
}

int	syntax_multline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			if (quote(str, &i))
				return (1);
		if (str[i] == '\"')
			if (dquote(str, &i))
				return (1);
		if (str[i] == '|')
			if (str[i + 1] == 0)
				return (syntax_error(PIPELINE_MULTI));
		i++;
	}
	return (0);
}
