/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:40:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/11 14:41:54 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

int		count_until_n(char *str);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *save, char *buf, int r);
int		ft_strchr_gnl(char *str, char c);
char	*ft_getline(char *save);
char	*ft_setnewline(char *save);
char	*ft_readline(int fd, char *save);
char	*get_next_line(int fd);

#endif