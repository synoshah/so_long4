/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:06:49 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:06:49 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	enemy_try_step(t_data *game, t_enemy *e, int dir)
{
	int		nx;
	char	target;

	nx = e->x + dir;
	if (nx <= 0 || nx >= game->w - 1)
		return (0);
	target = game->map[e->y][nx];
	if (target == TILE_WALL || target == TILE_EXIT || target == TILE_COLLECT
		|| target == TILE_ENEMY)
		return (0);
	if (target == TILE_PLAYER)
		close_game(game);
	game->map[e->y][e->x] = TILE_FLOOR;
	e->x = nx;
	game->map[e->y][e->x] = TILE_ENEMY;
	return (1);
}

void	bonus_enemy_update_and_check(t_data *game)
{
	int		i;
	int		moved;
	t_enemy	*e;

	if (!game->enemies || game->enemy_count <= 0)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		e = &game->enemies[i];
		moved = enemy_try_step(game, e, e->dir);
		if (!moved)
		{
			e->dir *= -1;
			enemy_try_step(game, e, e->dir);
		}
		i++;
	}
}
