/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:36:32 by nakhalil          #+#    #+#             */
/*   Updated: 2025/10/31 15:36:34 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	can_move(t_game *g, double nx, double ny)
{
	int	ix;
	int	iy;
	int	rowlen;

	ix = (int)nx;
	iy = (int)ny;
	if (iy < 0 || iy >= g->map.h)
		return (0);
	if (ix < 0)
		return (0);
	rowlen = (int)ft_strlen(g->map.grid[iy]);
	if (ix >= rowlen)
		return (1);
	return (g->map.grid[iy][ix] != '1');
}

static void	set_move(t_game *g, double xx, double yy)
{
	double	nx;
	double	ny;

	nx = xx;
	ny = yy;
	if (can_move(g, nx, g->pl.y))
		g->pl.x = nx;
	if (can_move(g, g->pl.x, ny))
		g->pl.y = ny;
}

static void	move_ws(t_game *g, double ms)
{
	double	nx;
	double	ny;

	nx = g->pl.x + g->pl.dir_x * ms;
	ny = g->pl.y + g->pl.dir_y * ms;
	if (g->keys.w)
		set_move(g, nx, ny);
	nx = g->pl.x - g->pl.dir_x * ms;
	ny = g->pl.y - g->pl.dir_y * ms;
	if (g->keys.s)
		set_move(g, nx, ny);
}

static void	move_ad(t_game *g, double ms)
{
	double	nx;
	double	ny;

	nx = g->pl.x + g->pl.dir_y * ms;
	ny = g->pl.y - g->pl.dir_x * ms;
	if (g->keys.a)
		set_move(g, nx, ny);
	nx = g->pl.x - g->pl.dir_y * ms;
	ny = g->pl.y + g->pl.dir_x * ms;
	if (g->keys.d)
		set_move(g, nx, ny);
}

void	handle_move(t_game *g)
{
	double	ms;

	ms = MOVE_SPEED;
	move_ws(g, ms);
	move_ad(g, ms);
}
