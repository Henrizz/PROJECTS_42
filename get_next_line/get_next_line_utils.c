/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:41:44 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/02/16 17:53:08 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

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
	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2)), sizeof(char const) + 1);
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

char	*ft_read_and_check(int fd, char *temp)
{
	char	*buffer;
	int		bytes_read;

	if (!temp)
		temp = (char *)ft_calloc(1, sizeof(char));
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (new_line_check(temp) == 0 && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

/*
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
