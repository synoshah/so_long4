/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:06:15 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:06:17 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_dup_or_die(t_data *game)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (game->h + 1));
	if (!copy)
		error_game(game, "Malloc failed");
	y = 0;
	while (y < game->h)
	{
		copy[y] = ft_strdup(game->map[y]);
		if (!copy[y])
		{
			copy[y] = NULL;
			free_map(copy);
			error_game(game, "Malloc failed");
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

static void	flood_fill(char **m, t_data *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->w || y >= game->h
		|| m[y][x] == '1' || m[y][x] == 'V')
		return ;
	m[y][x] = 'V';
	flood_fill(m, game, x + 1, y);
	flood_fill(m, game, x - 1, y);
	flood_fill(m, game, x, y + 1);
	flood_fill(m, game, x, y - 1);
}

static void	flood_fill_collect(char **m, t_data *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->w || y >= game->h)
		return ;
	if (m[y][x] == '1' || m[y][x] == 'V' || m[y][x] == TILE_EXIT)
		return ;
	m[y][x] = 'V';
	flood_fill_collect(m, game, x + 1, y);
	flood_fill_collect(m, game, x - 1, y);
	flood_fill_collect(m, game, x, y + 1);
	flood_fill_collect(m, game, x, y - 1);
}

static const char	*check_reachable(t_data *game, char **visited,
						char tile_target, const char *msg)
{
	int		i;
	int		j;
	char	tile;

	j = 0;
	while (j < game->h)
	{
		i = 0;
		while (i < game->w)
		{
			tile = game->map[j][i];
			if (tile == tile_target && visited[j][i] != 'V')
				return (msg);
			i++;
		}
		j++;
	}
	return (NULL);
}

void	validate_path(t_data *game)
{
	char			**copy;
	char			**copy2;
	const char		*msg;

	copy = map_dup_or_die(game);
	flood_fill_collect(copy, game, game->px, game->py);
	msg = check_reachable(game, copy, TILE_COLLECT,
			"No path to every collectibles");
	if (msg)
	{
		free_map(copy);
		error_game(game, msg);
	}
	free_map(copy);
	copy2 = map_dup_or_die(game);
	flood_fill(copy2, game, game->px, game->py);
	msg = check_reachable(game, copy2, TILE_EXIT, "No path to exit");
	if (msg)
	{
		free_map(copy2);
		error_game(game, msg);
	}
	free_map(copy2);
}
