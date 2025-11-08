/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_columns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:15:38 by nakhalil          #+#    #+#             */
/*   Updated: 2025/11/01 11:06:50 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	prepare_span_bounds(t_col *c, int *y, int *hh)
{
	*y = c->top;
	if (*y < 0)
		*y = 0;
	if (c->bot < c->top)
		c->bot = c->top;
	*hh = c->bot - c->top;
	if (*hh == 0)
		*hh = 1;
}

static int	draw_span_body(t_game *g, int x, t_col *c, double *tex_pos)
{
	int		y;
	int		hh;
	int		ty;
	int		col;
	double	step;

	prepare_span_bounds(c, &y, &hh);
	step = (double)g->tex[c->tex_id].img.h / (double)hh;
	while (y < c->bot && y < WIN_H)
	{
		if (y >= 0)
		{
			ty = (int)(*tex_pos);
			if (ty >= g->tex[c->tex_id].img.h)
				ty = g->tex[c->tex_id].img.h - 1;
			col = sample_tex(&g->tex[c->tex_id], c->tex_x, ty);
			put_px(&g->mlx.frame, x, y, col);
		}
		*tex_pos += step;
		y++;
	}
	return (y);
}

static void	draw_textured_body(t_game *g, int x, t_col c, double tex_pos)
{
	int	y_end;

	y_end = draw_span_body(g, x, &c, &tex_pos);
	draw_floor_from(g, x, y_end);
}

void	draw_column_tex(t_game *g, int x, t_col c)
{
	double	tex_pos;
	int		y;

	y = 0;
	while (y < c.top)
	{
		put_px(&g->mlx.frame, x, y, g->cfg.ceil_rgb);
		y++;
	}
	if (c.bot < 0)
		c.bot = 0;
	if (c.top < 0)
	{
		tex_pos = (double)(-c.top);
		tex_pos = tex_pos * (double)g->tex[c.tex_id].img.h;
		tex_pos = tex_pos / (double)(c.bot - c.top);
	}
	else
		tex_pos = 0.0;
	draw_textured_body(g, x, c, tex_pos);
}
