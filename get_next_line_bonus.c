#include "get_next_line_bonus.h"

char	*new_storage(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
	{
		return (NULL);
	}
	new = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*new == 0)
	{
		free(new);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (new);
}

char	*lineread(int fd, char *storage, char *buf)
{
	int		i;
	char	*temp;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(storage);
			return (NULL);
		}
		else if (i == 0)
			break ;
		buf[i] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[FD_LIMIT];
	char		*line;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(storage[fd]);
		free(buf);
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = lineread(fd, storage[fd], buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	storage[fd] = new_storage(line);
	return (line);
}
