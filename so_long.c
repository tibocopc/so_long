/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:35:32 by xx                #+#    #+#             */
/*   Updated: 2025/06/10 18:22:43 by xx               ###   ########.fr       */
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

int	main(void)
{
	t_game	*g;
	char	*map[] = {"11111111", "100C0E01", "100C0001", "1C000001",
			"10110P01", "11111111", NULL};

	g = malloc(sizeof(t_game));
	g->map = dup_map(map);
	g->mlx = mlx_init();
	get_height(g);
	get_width(g);
	g->win = mlx_new_window(g->mlx, 100 * g->h, 100 * g->w, "oggy");
	gen_map(g, 1);
	mlx_key_hook(g->win, key_lib, g);
	mlx_loop(g->mlx);
	ft_printf("%d", g->nb_move);
	destroy_all(g);
}
