/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:05:58 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:06:00 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "ft_printf.h"
# include "get_next_line.h"

# define TILE 32
# define TILE_FLOOR '0'
# define TILE_WALL '1'
# define TILE_PLAYER 'P'
# define TILE_COLLECT 'C'
# define TILE_EXIT 'E'

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		w;
	int		h;
	int		px;
	int		py;
	int		c_left;
	int		moves;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
}	t_data;

void	read_map(t_data *game, char *file);
void	validate_setup(t_data *game, const char *file);
void	validate_counts(t_data *game);
void	validate_path(t_data *game);
void	draw_map(t_data *game);
int		key_hook(int key, t_data *game);
int		close_game(t_data *game);
void	error_game(t_data *game, const char *msg);
void	error_exit(const char *msg);
void	free_map(char **map);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(const char *s, int fd);

#endif
