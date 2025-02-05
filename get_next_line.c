/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <szmadeja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:25:41 by szmadeja          #+#    #+#             */
/*   Updated: 2025/02/05 16:17:53 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_storage(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	new = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*new == 0)
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (new);
}

char	*lineread(int fd, char *storage, char *buf)
{
	int		i;
	char	*temp;

	//i = 1;
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
//		else if (i == 0)
//			break ;
		buf[i] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	if (i == -1)
	{
		free(storage);
		return (NULL);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free (storage);
		storage = NULL;
		return (NULL);
	}
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
