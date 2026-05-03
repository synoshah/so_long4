/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy_init_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:06:55 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:06:58 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_enemies(t_data *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == TILE_ENEMY)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	fill_enemies(t_data *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == TILE_ENEMY)
			{
				game->enemies[i].x = x;
				game->enemies[i].y = y;
				game->enemies[i].dir = 1;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	bonus_enemy_init(t_data *game)
{
	game->enemy_count = count_enemies(game);
	if (game->enemy_count <= 0)
	{
		game->enemies = NULL;
		return ;
	}
	game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
	if (!game->enemies)
		error_game(game, "malloc failed");
	fill_enemies(game);
}
