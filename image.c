/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:49:30 by xx                #+#    #+#             */
/*   Updated: 2025/06/23 13:33:58 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_immage(t_game *g)
{
	int	h;
	int	w;

	if (g->s)
		mlx_destroy_image(g->mlx, g->s);
	if (g->player)
		mlx_destroy_image(g->mlx, g->player);
	if (g->obj)
		mlx_destroy_image(g->mlx, g->obj);
	if (g->ec)
		mlx_destroy_image(g->mlx, g->ec);
	if (g->wall)
		mlx_destroy_image(g->mlx, g->wall);
	if (g->eo)
		mlx_destroy_image(g->mlx, g->eo);
	if (g->gwi)
		mlx_destroy_image(g->mlx, g->gwi);
	g->s = mlx_xpm_file_to_image(g->mlx, "img/s.xpm", &h, &w);
	g->player = mlx_xpm_file_to_image(g->mlx, "img/Oggy.xpm", &h, &w);
	g->obj = mlx_xpm_file_to_image(g->mlx, "img/caf.xpm", &h, &w);
	g->ec = mlx_xpm_file_to_image(g->mlx, "img/ec.xpm", &h, &w);
	g->wall = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", &h, &w);
	g->eo = mlx_xpm_file_to_image(g->mlx, "img/eo.xpm", &h, &w);
	g->gwi = mlx_xpm_file_to_image(g->mlx, "img/game_win.xpm", &h, &w);
	if (!g->s || !g->player || !g->obj || !g->wall || !g->ec || !g->eo
		|| !g->gwi)
	{
		destroy_all(g);
		exit(1);
	}
}
