/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:41:44 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/02/07 17:56:25 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char const) + 1);
	if (new == 0)
		return (0);
	while (s1[i] != 0)
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = 0;
	return (new);
}

//read into buffer + error handling
int	ft_read_and_check(int fd, char *buffer, size_t bytes, char *temp, char *line)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, bytes);
	if (bytes_read == -1)
	{
		free(temp);
		free(line);
		return (0);
	}
	if (bytes_read == 0)
	{
		free(temp);
		free(line);
		return (0);
	}
	return (bytes_read);
}

size_t	ft_strlcpy(char *dst, char *src, size_t	size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	i = 0;
	return (ft_strlen(src));
}
/*
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_length;

	i = 0;
	j = 0;
	dst[0] = '\0';
	dst_length = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] != 0 && i < size)
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	while (j < (size - i - 1) && src[j] != 0)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	if (size >= dst_length)
		return (dst_length + ft_strlen(src));
	return (size + ft_strlen(src));
}*/
