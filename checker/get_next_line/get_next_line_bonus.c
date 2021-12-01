#include "../checker.h"

int		is_newline(char *save)
{
	int	i;

	if (!save)
		return (0);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *save)
{
	int		i;
	int		dest_len;
	char	*dest;

	dest_len = 0;
	while (save[dest_len] != '\n' && save[dest_len])
		dest_len++;
	if (!(dest = (char *)malloc(dest_len + 1)))
		return (NULL);
	i = -1;
	while (++i < dest_len)
		dest[i] = save[i];
	dest[i] = '\0';
	return (dest);
}

char	*get_save(char *save)
{
	int		i;
	int		j;
	int		save_len;
	char	*dest;

	save_len = ft_strlen(save);
	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	i++;
	if (!(dest = (char *)malloc(save_len - i + 1)))
		return (NULL);
	j = 0;
	while (save[i])
		dest[j++] = save[i++];
	dest[j] = '\0';
	free(save);
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save[OPEN_MAX];
	int			read_len;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	read_len = 1;
	while (!is_newline(save[fd]) && read_len != 0)
	{
		if ((read_len = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[read_len] = '\0';
		if (!(save[fd] = ft_strjoin_gnl(save[fd], buff)))
			return (-1);
	}
	free(buff);
	*line = get_line(save[fd]);
	save[fd] = get_save(save[fd]);
	if (!save[fd])
		return (0);
	return (1);
}
