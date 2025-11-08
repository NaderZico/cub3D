/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:37:15 by nakhalil          #+#    #+#             */
/*   Updated: 2025/10/31 15:37:19 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate(t_game *g, double rt)
{
	double	odx;
	double	ody;

	odx = g->pl.dir_x;
	ody = g->pl.dir_y;
	g->pl.dir_x = odx * cos(rt) - ody * sin(rt);
	g->pl.dir_y = odx * sin(rt) + ody * cos(rt);
	odx = g->pl.plane_x;
	ody = g->pl.plane_y;
	g->pl.plane_x = odx * cos(rt) - ody * sin(rt);
	g->pl.plane_y = odx * sin(rt) + ody * cos(rt);
}

int	mouse_move_handle(t_game *g)
{
	int	mx;
	int	my;
	int	dx;
	int	dy;

	if (!g->mouse_captured)
		return (0);
	if (mlx_mouse_get_pos(g->mlx.win, &mx, &my) != 0)
		return (0);
	dx = mx - g->center_x;
	dy = my - g->center_y;
	if (dx)
		rotate(g, dx * ROT_SPEED * MOUSE_SENS_X);
	if (dy)
	{
		g->pl.pitch_ang -= (double)dy * MOUSE_SENS_Y_RAD;
		if (g->pl.pitch_ang > PITCH_MAX_RAD)
			g->pl.pitch_ang = PITCH_MAX_RAD;
		if (g->pl.pitch_ang < PITCH_MIN_RAD)
			g->pl.pitch_ang = PITCH_MIN_RAD;
	}
	mlx_mouse_move(g->mlx.win, g->center_x, g->center_y);
	return (0);
}

void	rotate_left_right(t_game *g)
{
	if (g->keys.left)
		rotate(g, -ROT_SPEED);
	if (g->keys.right)
		rotate(g, ROT_SPEED);
}
