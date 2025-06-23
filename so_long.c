/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:35:32 by xx                #+#    #+#             */
/*   Updated: 2025/06/23 13:29:03 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_lib(int keycode, t_game *g)
{
	if (g->game_wn == 1)
	{
		mlx_loop_end(g->mlx);
		return (0);
	}
	else
	{
		if (keycode == XK_Escape)
		{
			mlx_loop_end(g->mlx);
			return (0);
		}
		if (keycode == XK_w || keycode == XK_W)
			check_move_top(g);
		if (keycode == XK_s || keycode == XK_S)
			check_move_bot(g);
		if (keycode == XK_a || keycode == XK_A)
			check_move_left(g);
		if (keycode == XK_d || keycode == XK_D)
			check_move_right(g);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2)
		return (1);
	g = malloc(sizeof(t_game));
	if (!g)
		return (1);
	ft_memset(g, 0, sizeof(t_game));
	g->map = get_map(argv[1]);
	if (!g->map)
	{
		free(g);
		return (1);
	}
	g->mlx = mlx_init();
	if (!g->mlx)
		destroy_all(g);
	get_height(g);
	get_width(g);
	g->win = mlx_new_window(g->mlx, 100 * g->w, 100 * g->h, "oggy");
	mlx_key_hook(g->win, key_lib, g);
	gen_map(g, 1);
	mlx_loop(g->mlx);
	ft_printf("%d", g->nb_move);
	destroy_all(g);
	return (0);
}
