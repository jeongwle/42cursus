/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:50:48 by mki               #+#    #+#             */
/*   Updated: 2021/05/20 12:58:08 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	syntax_backslash(t_list *lst_begin)
{
	if (lst_begin->next == NULL)
		return (syntax_error(ERROR_BACKSLASH));
}
