/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:41:49 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/02/13 17:19:36 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//check if there is \n inside temp 
int	new_line_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_excerpt_line(char *temp)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = temp[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*keep_rest(char *temp)
{
	int		i;
	int		j;
	char	*new_temp;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0')
	{
		free(temp);
		return (NULL);
	}
	new_temp = (char *)malloc((ft_strlen(temp) - i + 1) * sizeof(char));
	if (!new_temp)
	{
		free(temp);
		return (NULL);
	}
	i++;
	while (temp[i] != '\0')
	{
		new_temp[j] = temp[i];
		j++;
		i++;
	}
	new_temp[i] = '\0';
	free(temp);
	return (new_temp);
}
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*temp;
	char		*line;
	int			bytes_read;
	
	bytes_read = 1;
	//printf("temp befor alloc: %s\n", temp);
	if (!temp)
		temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	//printf("temp after alloc: %s\n", temp);
	line = NULL;
	while (new_line_check(temp) == 0 && bytes_read != 0)
	{
		bytes_read = ft_read_and_check(fd, buffer, BUFFER_SIZE, temp, line);
		if (bytes_read == 0)
			return (NULL);
		temp = ft_strjoin(temp, buffer);
		if (!temp)
			return (NULL);
	}
	if (new_line_check(temp) == 1 || bytes_read == 0)
	{
		line = ft_excerpt_line(temp);
		//printf("line: %s, temp: %s\n", line, temp);
		if (!line)
			return (NULL);
		temp = keep_rest(temp);
		//printf("line2: %s, temp2: %s\n", line, temp);
		if (!temp)
			return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
