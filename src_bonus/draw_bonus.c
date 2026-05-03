/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:07:33 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:07:35 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_tile(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

static void	draw_cell(t_data *game, int x, int y)
{
	char	c;

	c = game->map[y][x];
	if (c == TILE_WALL)
		put_tile(game, game->wall, x, y);
	else
		put_tile(game, game->floor_img[game->anim_frame], x, y);
	if (c == TILE_COLLECT)
		put_tile(game, game->collect_img[game->anim_frame], x, y);
	else if (c == TILE_EXIT)
		put_tile(game, game->exit_img[game->anim_frame], x, y);
	else if (c == TILE_PLAYER)
		put_tile(game, game->player_img[game->anim_frame], x, y);
	else if (c == TILE_ENEMY)
		put_tile(game, game->enemy_img[game->anim_frame], x, y);
}

void	draw_map(t_data *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			draw_cell(game, x, y);
			x++;
		}
		y++;
	}
	bonus_draw_hud(game);
}
