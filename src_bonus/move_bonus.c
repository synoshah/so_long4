/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:08:40 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:08:42 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	try_to_move(t_data *game, int newx, int newy)
{
	char	target;

	if (newx < 0 || newy < 0 || newx >= game->w || newy >= game->h)
		return ;
	target = game->map[newy][newx];
	if (target == TILE_WALL)
		return ;
	if (target == TILE_ENEMY)
		close_game(game);
	if (target == TILE_EXIT && game->c_left != 0)
		return ;
	if (target == TILE_COLLECT)
		game->c_left--;
	game->map[game->py][game->px] = TILE_FLOOR;
	game->px = newx;
	game->py = newy;
	game->map[game->py][game->px] = TILE_PLAYER;
	game->moves++;
	draw_map(game);
	if (target == TILE_EXIT && game->c_left == 0)
		close_game(game);
}

int	key_hook(int key, t_data *game)
{
	if (key == KEY_ESC)
		close_game(game);
	else if (key == KEY_W)
		try_to_move(game, game->px, game->py - 1);
	else if (key == KEY_S)
		try_to_move(game, game->px, game->py + 1);
	else if (key == KEY_A)
		try_to_move(game, game->px - 1, game->py);
	else if (key == KEY_D)
		try_to_move(game, game->px + 1, game->py);
	return (0);
}
