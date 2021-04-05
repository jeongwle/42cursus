/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:21:53 by jeongwle          #+#    #+#             */
/*   Updated: 2021/04/05 19:34:48 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calc_something(int something, int i, unsigned char *bmp_h)
{
	bmp_h[i] = (unsigned char)(something);
	bmp_h[i + 1] = (unsigned char)(something >> 8);
	bmp_h[i + 2] = (unsigned char)(something >> 16);
	bmp_h[i + 3] = (unsigned char)(something >> 24);
}

void	write_bmp_header(t_param *p, int sizeimage, int size)
{
	unsigned char	bmpfileheader[54];
	int				i;

	i = -1;
	while (++i < 54)
		bmpfileheader[i] = (unsigned char)0;
	bmpfileheader[0] = (unsigned char)'B';
	bmpfileheader[1] = (unsigned char)'M';
	calc_something(size, 2, bmpfileheader);
	bmpfileheader[10] = (unsigned char)54;
	bmpfileheader[14] = (unsigned char)40;
	calc_something(p->width, 18, bmpfileheader);
	calc_something(-p->height, 22, bmpfileheader);
	bmpfileheader[26] = (unsigned char)1;
	bmpfileheader[28] = (unsigned char)32;
	calc_something(sizeimage, 34, bmpfileheader);
	if ((i = open("screenshot.bmp", O_CREAT | O_TRUNC | O_WRONLY |
	O_APPEND, 0666)) < 0)
		this_is_error(11);
	write(i, bmpfileheader, 54);
	write(i, p->data, sizeimage);
	close(i);
}

void	bitmap(t_param *p)
{
	int	sizeimage;
	int	size;
	int	error;

	sizeimage = p->width * 4 * p->height;
	size = sizeimage + 54;
	write_bmp_header(p, sizeimage, size);
	exit(0);
}
