/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:07:27 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:07:29 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	cleanup_images(t_data *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor_img[0])
		mlx_destroy_image(game->mlx, game->floor_img[0]);
	if (game->floor_img[1])
		mlx_destroy_image(game->mlx, game->floor_img[1]);
	if (game->player_img[0])
		mlx_destroy_image(game->mlx, game->player_img[0]);
	if (game->player_img[1])
		mlx_destroy_image(game->mlx, game->player_img[1]);
	if (game->collect_img[0])
		mlx_destroy_image(game->mlx, game->collect_img[0]);
	if (game->collect_img[1])
		mlx_destroy_image(game->mlx, game->collect_img[1]);
	if (game->exit_img[0])
		mlx_destroy_image(game->mlx, game->exit_img[0]);
	if (game->exit_img[1])
		mlx_destroy_image(game->mlx, game->exit_img[1]);
	if (game->enemy_img[0])
		mlx_destroy_image(game->mlx, game->enemy_img[0]);
	if (game->enemy_img[1])
		mlx_destroy_image(game->mlx, game->enemy_img[1]);
}

static void	cleanup(t_data *game)
{
	if (!game)
		return ;
	cleanup_images(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game->enemies);
	game->enemies = NULL;
	game->enemy_count = 0;
	free_map(game->map);
}

int	close_game(t_data *game)
{
	gnl_clear();
	cleanup(game);
	exit(0);
}

void	error_game(t_data *game, const char *msg)
{
	gnl_clear();
	ft_putstr_fd("Error\n", 2);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	cleanup(game);
	exit(1);
}
