/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:06:43 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:06:45 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_ber(t_data *game, const char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + (len - 4), ".ber", 4) != 0)
		error_game(game, "Map must end with .ber");
	if (len == 4 && ft_strncmp(file, ".ber", 4) == 0)
		error_game(game, "Map must end with .ber");
	if (len > 4 && file[len - 5] == '/')
		error_game(game, "Map must end with .ber");
}

static void	set_map_size(t_data *game)
{
	game->h = 0;
	while (game->map[game->h])
		game->h++;
	if (game->h == 0)
		error_game(game, "Empty map");
	game->w = (int)ft_strlen(game->map[0]);
	if (game->w == 0)
		error_game(game, "Empty map line");
}

static void	check_rectangular(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->h)
	{
		if ((int)ft_strlen(game->map[i]) != game->w)
			error_game(game, "Map must be a rectangle");
		i++;
	}
}

static void	check_walls(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->w)
	{
		if (game->map[0][i] != TILE_WALL)
			error_game(game, "Map must be surrounded by walls");
		if (game->map[game->h - 1][i] != TILE_WALL)
			error_game(game, "Map must be surrounded by walls");
		i++;
	}
	j = 0;
	while (j < game->h)
	{
		if (game->map[j][0] != TILE_WALL)
			error_game(game, "Map must be surrounded by walls");
		if (game->map[j][game->w - 1] != TILE_WALL)
			error_game(game, "Map must be surrounded by walls");
		j++;
	}
}

void	validate_setup(t_data *game, const char *file)
{
	check_ber(game, file);
	set_map_size(game);
	check_rectangular(game);
	check_walls(game);
	validate_counts(game);
	validate_path(game);
}
