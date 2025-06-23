/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:48:05 by xx                #+#    #+#             */
/*   Updated: 2025/06/17 14:24:45 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(char **src)
{
	int		i;
	char	**copy;

	i = 0;
	while (src[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
void	gen_map(t_game *g, int dp)
{
	int	i;
	int	j;

	count_c(g);
	init_immage(g);
	if (!g->s)
		return ;
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->obj, j * 100, i
					* 100);
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->wall, j * 100, i
					* 100);
			if (g->map[i][j] == 'E')
			{
				if (g->nbc == 0)
					mlx_put_image_to_window(g->mlx, g->win, g->eo, j * 100, i
						* 100);
				else
					mlx_put_image_to_window(g->mlx, g->win, g->ec, j * 100, i
						* 100);
			}
			if (g->map[i][j] == 'P')
			{
				mlx_put_image_to_window(g->mlx, g->win, g->player, j * 100, i
					* 100);
				if (dp == 1)
				{
					g->py = i;
					g->px = j;
				}
			}
			if (g->map[i][j] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->s, j * 100, i * 100);
			j++;
		}
		i++;
	}
}

char	**get_map(char *carte)
{
	char	**map;
	int		fd;
	char	*line;
	char	*all_lines;
	int		a;

	a = 1;
	line = 0;
	all_lines = NULL;
	fd = open(carte, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (a)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	map = ft_split(all_lines, '\n');
	free(all_lines);
	close(fd);
	return (map);
}

void	get_width(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[0][i])
		i++;
	g->w = i;
}

void	get_height(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	g->h = i;
}
