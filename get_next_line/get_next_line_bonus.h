/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:10:01 by anmassy           #+#    #+#             */
/*   Updated: 2022/11/29 17:33:19 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		size_line(char *strings, int i);
char	*get_next_line(int fd);

#endif
