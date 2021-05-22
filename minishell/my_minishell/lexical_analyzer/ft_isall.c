/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:18:13 by mki               #+#    #+#             */
/*   Updated: 2021/05/18 13:10:25 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		ft_isall(char c)
{
	return (ft_isdigit(c) || ft_isspecial(c) || ft_ismeta(c) ||\
		ft_isspace(c) || ft_isquotes(c));
}
