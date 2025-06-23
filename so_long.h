/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:35:51 by xx                #+#    #+#             */
/*   Updated: 2025/06/17 15:06:48 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "reprintf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct game
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*s;
	void	*obj;
	void	*wall;
	char	**map;
	int		px;
	int		py;
	int		nbc;
	void	*eo;
	void	*ec;
	int		ts;
	int		max_w;
	int		max_h;
	void	*gwi;
	int		w;
	int		h;
	int		gw;
	int		game_wn;
	int		nb_move;
}			t_game;

void		check_move_top(t_game *g);
void		move_player_top(t_game *g);
void		check_move_bot(t_game *g);
void		check_move_left(t_game *g);
void		check_move_right(t_game *g);
void		move_player_bot(t_game *g);
void		move_player_left(t_game *g);
void		move_player_right(t_game *g);
void		init_immage(t_game *g);
void		gen_map(t_game *g, int dp);
void		count_c(t_game *g);
void		game_win(t_game *g);
void		destroy_all(t_game *g);
void		get_width(t_game *g);
void		get_height(t_game *g);
int			check_exit(t_game *g);
char		**get_map(char *carte);
char		**dup_map(char **src);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
static int	len_num(int nb);
char		*ft_strdup(const char *s);
void		*ft_memset(void *s, int c, size_t n);

#endif

// nbc nombre de collectible sur la map