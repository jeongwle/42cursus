/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:38:30 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/04 14:51:53 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	if_so(t_param *p, char *line, int i)
{
	if (p->so_flag)
		this_is_error(2);
	if (!is_space(line[i + 2]))
		this_is_error(10);
	i += 2;
	do_check_texture(line, i, 2);
	while (is_space(line[i]))
			i++;
	p->texpath[1] = ft_strdup(&line[i]);
	if (open(p->texpath[1], O_RDONLY) < 0)
		this_is_error(2);
	p->so_flag = 1;
	p->identifier_count++;
}

void	if_s(t_param *p, char *line, int i)
{
	if (p->s_flag)
		this_is_error(3);
	if (!is_space(line[i + 1]))
		this_is_error(10);
	i++;
	do_check_texture(line, i, 3);
	while (is_space(line[i]))
		i++;
	p->texpath[4] = ft_strdup(&line[i]);
	if (open(p->texpath[4], O_RDONLY) < 0)
		this_is_error(3);
	p->s_flag = 1;
	p->identifier_count++;
}

void	if_w(t_param *p, char *line, int i)
{
	if (p->w_flag)
		this_is_error(4);
	if (!is_space(line[i + 2]))
		this_is_error(10);
	i += 2;
	do_check_texture(line, i , 4);
	while (is_space(line[i]))
		i++;
	p->texpath[3] = ft_strdup(&line[i]);
	if (open(p->texpath[3], O_RDONLY) < 0)
		this_is_error(4);
	p->w_flag = 1;
	p->identifier_count++;
}

void	if_n(t_param *p, char *line, int i)
{
	if (p->n_flag)
		this_is_error(5);
	if (!is_space(line[i + 2]))
		this_is_error(10);
	i += 2;
	do_check_texture(line, i, 5);
	while (is_space(line[i]))
		i++;
	p->texpath[0] = ft_strdup(&line[i]);
	if (open(p->texpath[0], O_RDONLY) < 0)
		this_is_error(5);
	p->n_flag = 1;
	p->identifier_count++;
}

void	if_e(t_param *p, char *line, int i)
{
	if (p->e_flag)
		this_is_error(6);
	if (!is_space(line[i + 2]))
		this_is_error(10);
	i += 2;
	do_check_texture(line, i, 6);
	while (is_space(line[i]))
		i++;
	p->texpath[2] = ft_strdup(&line[i]);
	if (open(p->texpath[2], O_RDONLY) < 0)
		this_is_error(6);
	p->e_flag = 1;
	p->identifier_count++;
}
