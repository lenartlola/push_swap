/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:59:35 by hsabir            #+#    #+#             */
/*   Updated: 2021/12/02 13:39:50 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_next_line(char **s)
{
	char	*out;
	char	*tmp;
	size_t	len;

	len = 0;
	out = NULL;
	while ((*s)[len] != '\n' && (*s)[len])
		len++;
	if ((*s)[len] == '\n')
	{
		out = ft_substr(*s, 0, len + 1);
		tmp = ft_strdup(*s + len + 1);
		free(*s);
		*s = tmp;
		if (!**s)
		{
			free(*s);
			*s = NULL;
		}
		return (out);
	}
	out = ft_strdup(*s);
	free(*s);
	*s = NULL;
	return (out);
}

static char	*check_and_return(char **s, ssize_t n, int fd)
{
	if (n < 0)
		return (NULL);
	if (!n && (!s[fd] || !*s[fd]))
		return (NULL);
	return (return_next_line(&s[fd]));
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buf;
	static char	*s[FD_SIZE];
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup("");
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (check_and_return(s, n, fd));
}
