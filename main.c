/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakhalil <nakhalil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:39:09 by nakhalil          #+#    #+#             */
/*   Updated: 2025/11/01 12:55:42 by nakhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	usage(void)
{
	write(2, "Error\n", 6);
	write(2, "usage: ./cub3d <map.cub>\n", 25);
}

static int	setup_hooks(t_game *g)
{
	mlx_key_hook(g->mlx.win, &key_release, g);
	mlx_hook(g->mlx.win, 2, 1L << 0, &key_press, g);
	mlx_hook(g->mlx.win, 3, 1L << 1, &key_release, g);
	mlx_hook(g->mlx.win, 17, 0, &on_close, g);
	mlx_expose_hook(g->mlx.win, &expose_redraw, g);
	mlx_loop_hook(g->mlx.ptr, &game_loop, g);
	mlx_mouse_hide();
	g->mouse_captured = 1;
	mlx_mouse_move(g->mlx.win, g->center_x, g->center_y);
	return (1);
}

static int	init_player_from_map(t_game *g)
{
	return (g->pl.x != 0);
}

int	main(int ac, char **av)
{
	t_game	g;

	ft_bzero(&g, sizeof(g));
	if (ac != 2)
		return (usage(), 1);
	if (!load_cub(&g, av[1]))
		return (1);
	if (!init_player_from_map(&g))
		return (game_destroy(&g, "Error\ninvalid player\n", 1), 1);
	if (!game_init(&g))
		return (1);
	if (!setup_hooks(&g))
		return (game_destroy(&g, "Error\ninit hooks\n", 1), 1);
	mlx_loop(g.mlx.ptr);
	return (0);
}
