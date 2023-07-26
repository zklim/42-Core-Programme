/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:55:52 by zhlim             #+#    #+#             */
/*   Updated: 2022/12/28 10:23:40 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

int		count_until_n(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *save, char *buf, int r);
int		ft_strchr(char *str, char c);
char	*ft_getline(char *save);
char	*ft_setnewline(char *save);
char	*ft_readline(int fd, char *save);
char	*get_next_line(int fd);

#endif