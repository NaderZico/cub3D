/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:37:38 by nakhalil          #+#    #+#             */
/*   Updated: 2025/10/31 15:53:44 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_close(void *p)
{
	game_destroy((t_game *)p, NULL, 0);
	return (0);
}

int	expose_redraw(void *p)
{
	(void)p;
	return (0);
}

int	game_loop(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	handle_move(g);
	rotate_left_right(g);
	mouse_move_handle(g);
	draw_frame(g);
	mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->mlx.frame.ptr, 0, 0);
	return (0);
}
