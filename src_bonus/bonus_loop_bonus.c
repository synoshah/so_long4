/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_loop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:07:08 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:07:10 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	bonus_loop(t_data *game)
{
	int	redraw;

	redraw = 0;
	if (!game || !game->win)
		return (0);
	game->tick++;
	if ((game->tick % 10) == 0)
	{
		game->anim_frame = (game->anim_frame + 1) % 2;
		redraw = 1;
	}
	if ((game->tick % 1500) == 0)
	{
		bonus_enemy_update_and_check(game);
		redraw = 1;
	}
	if (redraw)
		draw_map(game);
	return (0);
}
