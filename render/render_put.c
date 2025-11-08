/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:15:27 by nakhalil          #+#    #+#             */
/*   Updated: 2025/10/31 17:15:28 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_px(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return ;
	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

int	sample_tex(t_tex *t, int tx, int ty)
{
	char	*px;

	if (tx < 0)
		tx = 0;
	if (ty < 0)
		ty = 0;
	if (tx >= t->img.w)
		tx = t->img.w - 1;
	if (ty >= t->img.h)
		ty = t->img.h - 1;
	px = t->img.addr + (ty * t->img.line + tx * (t->img.bpp / 8));
	return (*(unsigned int *)px);
}
