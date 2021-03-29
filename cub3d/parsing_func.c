/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:38:30 by jeongwle          #+#    #+#             */
/*   Updated: 2021/03/29 20:07:49 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	if_so(t_param *p, char *line, int i)
{
	i += 2;
	while (is_space(line[i]))
		i++;
	p->texpath[1] = ft_strdup(&line[i]);
}

void	if_s(t_param *p, char *line, int i)
{
	i++;
	while (is_space(line[i]))
		i++;
	p->texpath[4] = ft_strdup(&line[i]);
}

void	if_w(t_param *p, char *line, int i)
{
	i += 2;
	while (is_space(line[i]))
		i++;
	p->texpath[3] = ft_strdup(&line[i]);
}

void	if_n(t_param *p, char *line, int i)
{
	i += 2;
	while (is_space(line[i]))
		i++;
	p->texpath[0] = ft_strdup(&line[i]);
}

void	if_e(t_param *p, char *line, int i)
{
	i += 2;
	while (is_space(line[i]))
		i++;
	p->texpath[2] = ft_strdup(&line[i]);
}
