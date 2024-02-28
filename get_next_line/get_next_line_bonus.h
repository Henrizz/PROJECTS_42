/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:03 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/02/28 13:38:05 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# define MAX_FD 10240

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h> //this for RDONLY FLAG, maybe delete in the end
# include <stdio.h> // just to test print

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_and_check(int fd, char *temp);
char	*ft_excerpt_line(char *temp);
char	*keep_rest(char *temp);
int		new_line_check(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
