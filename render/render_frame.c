/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:15:49 by nakhalil          #+#    #+#             */
/*   Updated: 2025/11/01 10:14:59 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_col(t_game *g, t_rayhit *h, t_rdir d, t_col *c)
{
	int	flip;

	c->tex_id = h->ori;
	c->tex_x = (int)(h->wx * (double)g->tex[c->tex_id].img.w);
	if (c->tex_x < 0)
		c->tex_x = 0;
	if (c->tex_x >= g->tex[c->tex_id].img.w)
		c->tex_x = g->tex[c->tex_id].img.w - 1;
	flip = 0;
	if ((h->ori == 2 || h->ori == 3) && d.y < 0.0)
		flip = 1;
	if ((h->ori == 0 || h->ori == 1) && d.x > 0.0)
		flip = 1;
	if (flip)
		c->tex_x = g->tex[c->tex_id].img.w - c->tex_x - 1;
}

static void	draw_x(t_game *g, int x, int pitchi)
{
	double		cam;
	t_rdir		d;
	t_rayhit	h;
	int			hh;
	t_col		c;

	cam = 2.0 * (double)x / (double)WIN_W - 1.0;
	d.x = g->pl.dir_x + g->pl.plane_x * cam;
	d.y = g->pl.dir_y + g->pl.plane_y * cam;
	if (!raycast_cell(g, d.x, d.y, &h))
	{
		draw_column_flat_wrap(g, x, pitchi);
		return ;
	}
	hh = (int)((double)WIN_H / h.walld);
	c.top = -hh / 2 + WIN_H / 2 + pitchi;
	c.bot = hh / 2 + WIN_H / 2 + pitchi;
	setup_col(g, &h, d, &c);
	draw_column_tex(g, x, c);
}

void	draw_frame(t_game *g)
{
	int		x;
	double	shift;
	int		pitchi;

	shift = tan(g->pl.pitch_ang) * (WIN_H / 2.0);
	if (shift > 100000.0)
		shift = 100000.0;
	if (shift < -100000.0)
		shift = -100000.0;
	pitchi = (int)shift;
	x = 0;
	while (x < WIN_W)
	{
		draw_x(g, x, pitchi);
		x++;
	}
}
