/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:18:16 by synoshah          #+#    #+#             */
/*   Updated: 2026/05/03 15:13:07 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	line_len(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

static char	*make_line(char *stash)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = line_len(stash);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_fd(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (ft_strchr(stash, '\n') == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	return (stash);
}

static char	*cut_stash(char *stash)
{
	size_t	len;
	size_t	i;
	char	*rest;

	i = 0;
	len = line_len(stash);
	if (stash[len] == '\0')
		return (NULL);
	rest = malloc(ft_strlen(stash + len) + 1);
	if (rest == NULL)
		return (NULL);
	while (stash[len + i])
	{
		rest[i] = stash[len + i];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*next;
	char		**stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = gnl_stash_addr();
	*stash = read_fd(fd, *stash);
	if (*stash == NULL)
		return (NULL);
	line = make_line(*stash);
	if (line == NULL)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	next = cut_stash(*stash);
	free(*stash);
	*stash = next;
	return (line);
}
