/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:49:30 by xx                #+#    #+#             */
/*   Updated: 2025/06/09 19:56:59 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_immage(t_game *g)
{
	int h;
	int w;

	g->s = mlx_xpm_file_to_image(g->mlx, "img/s.xpm", &h, &w);
	g->player = mlx_xpm_file_to_image(g->mlx, "img/Oggy.xpm", &h, &w);
	g->obj = mlx_xpm_file_to_image(g->mlx, "img/caf.xpm", &h, &w);
	g->ec = mlx_xpm_file_to_image(g->mlx, "img/ec.xpm", &h, &w);
	g->wall = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", &h, &w);
	g->eo = mlx_xpm_file_to_image(g->mlx, "img/eo.xpm", &h, &w);
	g->gwi = mlx_xpm_file_to_image(g->mlx, "img/game_win.xpm", &h, &w);
}