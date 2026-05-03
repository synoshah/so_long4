/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:08:24 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:08:26 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*xpm(t_data *game, char *path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, w, h);
	if (!img)
		error_game(game, "Error");
	return (img);
}

static void	load_textures(t_data *game)
{
	int	w;
	int	h;

	game->wall = xpm(game, "textures/wall.xpm", &w, &h);
	game->floor_img[0] = xpm(game, "textures/floor.xpm", &w, &h);
	game->floor_img[1] = xpm(game, "textures/floor2.xpm", &w, &h);
	game->player_img[0] = xpm(game, "textures/character.xpm", &w, &h);
	game->player_img[1] = xpm(game, "textures/character2.xpm", &w, &h);
	game->collect_img[0] = xpm(game, "textures/collectable.xpm", &w, &h);
	game->collect_img[1] = xpm(game, "textures/collectable2.xpm", &w, &h);
	game->exit_img[0] = xpm(game, "textures/exit.xpm", &w, &h);
	game->exit_img[1] = xpm(game, "textures/exit2.xpm", &w, &h);
	game->enemy_img[0] = xpm(game, "textures/enemy.xpm", &w, &h);
	game->enemy_img[1] = xpm(game, "textures/enemy2.xpm", &w, &h);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		error_exit("Error");
	game = (t_data){0};
	read_map(&game, argv[1]);
	bonus_enemy_init(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_game(&game, "Error");
	game.win = mlx_new_window(game.mlx,
			game.w * TILE, game.h * TILE, "so_long_bonus");
	if (!game.win)
		error_game(&game, "Error");
	load_textures(&game);
	draw_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, bonus_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
