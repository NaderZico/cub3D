/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_columns_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:41:38 by nakhalil          #+#    #+#             */
/*   Updated: 2025/11/01 10:41:39 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clamp_mid(int mid)
{
	if (mid < 0)
		return (0);
	if (mid > WIN_H)
		return (WIN_H);
	return (mid);
}

void	draw_ceiling_until(t_game *g, int x, int endy)
{
	int	y;

	y = 0;
	while (y < endy)
	{
		put_px(&g->mlx.frame, x, y, g->cfg.ceil_rgb);
		y++;
	}
}

void	draw_floor_from(t_game *g, int x, int starty)
{
	int	y;

	y = starty;
	while (y < WIN_H)
	{
		put_px(&g->mlx.frame, x, y, g->cfg.floor_rgb);
		y++;
	}
}

void	draw_column_flat(t_game *g, int x, int pitchi)
{
	int	mid;

	mid = WIN_H / 2 + pitchi;
	mid = clamp_mid(mid);
	draw_ceiling_until(g, x, mid);
	draw_floor_from(g, x, mid);
}

void	draw_column_flat_wrap(t_game *g, int x, int pitchi)
{
	draw_column_flat(g, x, pitchi);
}
