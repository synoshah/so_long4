/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_counts_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:09:13 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:09:15 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_counts(t_data *game, int p_count, int e_count, int c_count)
{
	if (p_count < 1)
		error_game(game, "No start");
	if (p_count > 1)
		error_game(game, "Multiple starts");
	if (e_count < 1)
		error_game(game, "No exit");
	if (e_count > 1)
		error_game(game, "Multiple exits");
	if (c_count < 1)
		error_game(game, "No collectible");
	game->c_left = c_count;
}

static void	count_tile(t_data *game, int x, int y, int *counts)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == TILE_PLAYER)
	{
		counts[0]++;
		game->px = x;
		game->py = y;
	}
	else if (tile == TILE_EXIT)
		counts[1]++;
	else if (tile == TILE_COLLECT)
		counts[2]++;
	else if (tile == TILE_ENEMY)
		return ;
	else if (tile != TILE_FLOOR && tile != TILE_WALL)
		error_game(game, "Invalid character in map");
}

void	validate_counts(t_data *game)
{
	int	i;
	int	j;
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	j = 0;
	while (j < game->h)
	{
		i = 0;
		while (i < game->w)
		{
			count_tile(game, i, j, counts);
			i++;
		}
		j++;
	}
	check_counts(game, counts[0], counts[1], counts[2]);
}
