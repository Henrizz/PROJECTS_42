/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:03 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/02/16 17:57:03 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# define BUFFER_SIZE 4

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> //this for RDONLY FLAG, maybe delete in the end
# include <stdio.h> // just to test print

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read_and_check(int fd, char *temp);
char	*ft_excerpt_line(char *temp);
char	*keep_rest(char *temp);
int		new_line_check(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
