/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 01:43:54 by thde-sou          #+#    #+#             */
/*   Updated: 2026/01/25 02:21:01 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static int	safe_buf(char *buf)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		i++;
		found = 1;
	}
	while (buf[i])
		buf[j++] = buf[i++];
	buf[j] = '\0';
	return (found);
}

static char	*mount_line(char *line, char *buf)
{
	int		i;
	int		j;
	int		size;
	char	*out;

	i = 0;
	j = 0;
	size = str_len(line) + str_len(buf) + 1;
	out = malloc(sizeof(char) * size);
	if (!out)
		return (NULL);
	if (line)
	{
		while (line[j])
			out[i++] = line[j++];
	}
	j = 0;
	while (buf[j] && buf[j] != '\n')
		out[i++] = buf[j++];
	if (buf[j] == '\n')
		out[i++] = '\n';
	out[i] = '\0';
	free(line);
	return (out);
}

static int	read_buf(int fd, char *buf, int *n)
{
	if (buf[0] != '\0')
		return (1);
	*n = read(fd, buf, BUFFER_SIZE);
	if (*n <= 0)
		return (0);
	buf[*n] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	n = 1;
	while (read_buf(fd, buf, &n))
	{
		line = mount_line(line, buf);
		if (!line)
			return (NULL);
		if (safe_buf(buf))
			return (line);
	}
	if (line && line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
}
