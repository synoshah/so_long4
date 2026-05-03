/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hud_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:07:02 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 13:07:04 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	append_str(char *dst, int i, const char *s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		dst[i] = s[j];
		i++;
		j++;
	}
	return (i);
}

static int	append_int(char *dst, int i, int n)
{
	char	buf[12];
	int		k;
	long	nb;

	nb = n;
	if (nb == 0)
	{
		dst[i++] = '0';
		return (i);
	}
	if (nb < 0)
	{
		dst[i++] = '-';
		nb = -nb;
	}
	k = 0;
	while (nb > 0 && k < 11)
	{
		buf[k++] = '0' + (nb % 10);
		nb /= 10;
	}
	while (k > 0)
		dst[i++] = buf[--k];
	return (i);
}

void	bonus_draw_hud(t_data *game)
{
	char	text[64];
	int		i;

	if (!game || !game->mlx || !game->win)
		return ;
	i = 0;
	i = append_str(text, i, "Moves: ");
	i = append_int(text, i, game->moves);
	text[i] = 0;
	mlx_string_put(game->mlx, game->win, 8, 20, 0xFFFFFF, text);
}
