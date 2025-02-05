/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:15:07 by szmadeja          #+#    #+#             */
/*   Updated: 2025/01/27 20:16:45 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nstr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	while (s1[i])
	{
		nstr[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		nstr[j] = s2[i];
		i++;
		j++;
	}
	nstr[j] = '\0';
	return (nstr);
}

void	*ft_calloc(size_t nmem, size_t n)
{
	void	*ptr;

	if (nmem != 0 && n > SIZE_MAX / nmem)
		return (NULL);
	ptr = (void *)malloc(nmem * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmem * n);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
