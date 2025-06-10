/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:46:47 by xx                #+#    #+#             */
/*   Updated: 2025/06/10 17:45:37 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_right(t_game *g)
{
	if (check_exit(g) == 0)
		g->map[g->py][g->px] = 'E';
	else
		g->map[g->py][g->px] = '0';
	g->map[g->py][g->px + 1] = 'P';
	g->nb_move++;
	g->px++;
	gen_map(g, 0);
}

void	move_player_left(t_game *g)
{
	if (check_exit(g) == 0)
		g->map[g->py][g->px] = 'E';
	else
		g->map[g->py][g->px] = '0';
	g->map[g->py][g->px - 1] = 'P';
	g->nb_move++;
	g->px--;
	gen_map(g, 0);
}

void	move_player_bot(t_game *g)
{
	if (check_exit(g) == 0)
		g->map[g->py][g->px] = 'E';
	else
		g->map[g->py][g->px] = '0';
	g->map[g->py + 1][g->px] = 'P';
	g->nb_move++;
	g->py++;
	gen_map(g, 0);
}

void	move_player_top(t_game *g)
{
	if (check_exit(g) == 0)
		g->map[g->py][g->px] = 'E';
	else
		g->map[g->py][g->px] = '0';
	g->map[g->py - 1][g->px] = 'P';
	g->nb_move++;
	g->py--;
	gen_map(g, 0);
}
