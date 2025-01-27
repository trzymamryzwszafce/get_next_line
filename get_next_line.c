/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:25:41 by szmadeja          #+#    #+#             */
/*   Updated: 2025/01/27 20:32:48 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joinfree(char *storage, char *temp)
{
	temp = storage;
	ft_strjoin(storage, temp);
	free(temp);
	return (storage);
}

char	*lineread(char *storage, int fd)
{
	int		i;
	char	*temp;

	i = 1
	while (i > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		i = read(fd, storage, BUFFER_SIZE);
		if (i == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[i] = '\0';
		if (strchr(storage, '\n'))
			break ;

		joinfree(storage, temp);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
}
