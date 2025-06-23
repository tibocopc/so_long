/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:13:12 by xx                #+#    #+#             */
/*   Updated: 2025/06/19 14:48:01 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_win(t_game *g)
{
	int	mid_w;
	int	mid_h;

	g->game_wn = 1;
	mid_h = (g->h * 100 - 432) / 2;
	mid_w = (g->w * 100 - 768) / 2;
	mlx_clear_window(g->mlx, g->win);
	mlx_put_image_to_window(g->mlx, g->win, g->gwi, mid_w, mid_h);
}

void	destroy_all(t_game *g)
{
	int	i;

	if (!g)
		return ;
	if (g->mlx)
	{
		if (g->s)
			mlx_destroy_image(g->mlx, g->s);
		if (g->player)
			mlx_destroy_image(g->mlx, g->player);
		if (g->obj)
			mlx_destroy_image(g->mlx, g->obj);
		if (g->wall)
			mlx_destroy_image(g->mlx, g->wall);
		if (g->ec)
			mlx_destroy_image(g->mlx, g->ec);
		if (g->eo)
			mlx_destroy_image(g->mlx, g->eo);
		if (g->gwi)
			mlx_destroy_image(g->mlx, g->gwi);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	if (g->map)
	{
		i = 0;
		while (g->map[i])
		{
			free(g->map[i]);
			i++;
		}
		free(g->map);
	}
	free(g);
}
