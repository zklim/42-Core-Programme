/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:55:26 by zhlim             #+#    #+#             */
/*   Updated: 2022/12/28 11:02:59 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char	*ft_getline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save || !save[i])
		return (NULL);
	i = count_until_n(save);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
		if (save[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_setnewline(char *save)
{
	char	*res;
	int		i;
	int		j;
	int		remain;

	i = 0;
	j = 0;
	if (!save || !save[i])
		return (NULL);
	i = count_until_n(save);
	remain = ft_strlen(save) - i;
	if (!remain)
	{
		free(save);
		return (NULL);
	}
	res = malloc(sizeof(char) * (remain + 1));
	if (!res)
		return (NULL);
	while (j < remain)
		res[j++] = save[i++];
	res[j] = '\0';
	free(save);
	return (res);
}

char	*ft_readline(int fd, char *save)
{
	int		r;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		save = ft_strjoin(save, buf, r);
		if (ft_strchr(save, '\n'))
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (r == -1)
	{
		if (save)
			free(save);
		return (NULL);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_readline(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_getline(save[fd]);
	save[fd] = ft_setnewline(save[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	int		i;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	i = 5;
// 	while (i)
// 	{
// 		printf("\"%dth\"\n", i);
// 		line = get_next_line(fd);
// 		if (!line)
// 			printf("NULL returned\n");
// 		else
// 			printf("line: %s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		if (!line)
// 			printf("NULL returned\n");
// 		else
// 			printf("line: %s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		if (!line)
// 			printf("NULL returned\n");
// 		else
// 			printf("line: %s", line);
// 		free(line);
// 		i--;
// 	}
// 	close(fd);
// }
