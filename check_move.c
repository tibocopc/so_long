/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:47:27 by xx                #+#    #+#             */
/*   Updated: 2025/06/19 14:48:32 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_move_left(t_game *g)
{
	if (g->map[g->py][g->px - 1] == 'E' && g->nbc == 0)
	{
		move_player_left(g);
		game_win(g);
		return ;
	}
	if (g->map[g->py][g->px - 1] != '1')
		move_player_left(g);
	if (g->map[g->py][g->px - 1] == 'C')
		g->nbc--;
}

void	check_move_bot(t_game *g)
{
	if (g->map[g->py + 1][g->px] == 'E' && g->nbc == 0)
	{
		move_player_bot(g);
		game_win(g);
		return ;
	}
	if (g->map[g->py + 1][g->px] == 'C')
		g->nbc--;
	if (g->map[g->py + 1][g->px] != '1')
		move_player_bot(g);
}

void	check_move_top(t_game *g)
{
	if (g->map[g->py - 1][g->px] == 'E' && g->nbc == 0)
	{
		move_player_top(g);
		game_win(g);
		return ;
	}
	if (g->map[g->py - 1][g->px] == 'C')
		g->nbc--;
	if (g->map[g->py - 1][g->px] != '1')
		move_player_top(g);
}

void	check_move_right(t_game *g)
{
	if (g->map[g->py][g->px + 1] == 'E' && g->nbc == 0)
	{
		move_player_right(g);
		game_win(g);
		return ;
	}
	if (g->map[g->py][g->px + 1] == 'C')
		g->nbc--;
	if (g->map[g->py][g->px + 1] != '1')
		move_player_right(g);
}

int	check_exit(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
