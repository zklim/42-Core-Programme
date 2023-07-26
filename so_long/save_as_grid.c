/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_as_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:21:19 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 16:02:54 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	grid_dup(char **new_grid, t_map *map, int count)
{
	int	i;

	i = 0;
	count--;
	while (i < count)
	{
		new_grid[i] = map->grid[i];
		i++;
	}
	return (i);
}

char	**create_grid(t_map *map, char *line)
{
	char	**new_grid;
	int		i;

	new_grid = (char **)malloc(map->rows * sizeof(char *));
	if (!new_grid)
		return (NULL);
	if (map->grid)
	{
		i = grid_dup(new_grid, map, map->rows);
		free(map->grid);
	}
	else
	{
		i = 0;
	}
	new_grid[i] = ft_strdup(line);
	return (new_grid);
}

void	save_as_grid(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\n')
			break ;
		map->rows++;
		map->grid = create_grid(map, line);
		free(line);
		line = get_next_line(fd);
	}
}
