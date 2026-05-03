/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_stash.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:25:00 by synoshah          #+#    #+#             */
/*   Updated: 2026/02/08 22:25:00 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**gnl_stash_addr(void)
{
	static char	*stash;

	return (&stash);
}

void	gnl_clear(void)
{
	char	**stash;

	stash = gnl_stash_addr();
	free(*stash);
	*stash = NULL;
}
