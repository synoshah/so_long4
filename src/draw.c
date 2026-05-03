/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:04:49 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:04:55 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

void	draw_map(t_data *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			c = game->map[y][x];
			if (c == TILE_WALL)
				put_tile(game, game->wall, x, y);
			else
				put_tile(game, game->floor, x, y);
			if (c == TILE_COLLECT)
				put_tile(game, game->collect, x, y);
			else if (c == TILE_EXIT)
				put_tile(game, game->exit, x, y);
			else if (c == TILE_PLAYER)
				put_tile(game, game->player, x, y);
			x++;
		}
		y++;
	}
}
