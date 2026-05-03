/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:04:19 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:04:25 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cleanup_images(t_data *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
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
