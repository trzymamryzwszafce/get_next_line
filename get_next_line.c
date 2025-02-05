/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:25:41 by szmadeja          #+#    #+#             */
/*   Updated: 2025/02/03 19:49:39 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = ft_strlen(s);
	if (start > i)
		return (ft_strdup(""));
	if (len > i - start)
		len = i - start;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	dup = ft_calloc(i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*new_storage(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
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
			free(buf);
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
	static char	*storage;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1); 
	if (!buf)
		return (NULL);
	line = lineread(fd, storage, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	storage = new_storage(line);
	return (line);
}

//#include <stdio.h>
/*
int	main()
{
	char *line;
	int i = 0;
	int fd = open("test.txt", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	//free(line);
	return (0);
}*/
