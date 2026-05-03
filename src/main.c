/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:04:59 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 18:42:40 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_textures(t_data *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/character.xpm", &w, &h);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collectable.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->wall || !game->floor || !game->player || !game->collect
		|| !game->exit)
		error_game(game, "Error");
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		error_exit("Error");
	game = (t_data){0};
	read_map(&game, argv[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_game(&game, "Error");
	game.win = mlx_new_window(game.mlx,
			game.w * TILE, game.h * TILE, "so_long");
	if (!game.win)
		error_game(&game, "Error");
	load_textures(&game);
	draw_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
