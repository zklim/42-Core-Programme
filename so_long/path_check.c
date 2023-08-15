/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:23:18 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 15:01:44 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**temp_grid(t_map *map)
{
	char	**new_grid;
	int		i;

	i = 0;
	new_grid = (char **)malloc(map->rows * sizeof(char *));
	if (!new_grid)
		return (NULL);
	while (i < map->rows)
	{
		new_grid[i] = ft_strdup(map->grid[i]);
		i++;
	}
	return (new_grid);
}

void	flood_fill(t_map *temp_map, int col, int row)
{
	char	*current_coord;

	current_coord = &temp_map->grid[row][col];
	if (row >= temp_map->rows || row < 0 || col >= temp_map->columns || col < 0
		|| *current_coord == WALL)
		return ;
	if (*current_coord == EXIT)
	{
		temp_map->exited = 1;
		return ;
	}
	if (*current_coord == COLLECTIBLE)
	{
		temp_map->collected++;
		*current_coord = EMPTY;
	}
	*current_coord = WALL;
	flood_fill(temp_map, col, row - 1);
	flood_fill(temp_map, col, row + 1);
	flood_fill(temp_map, col - 1, row);
	flood_fill(temp_map, col + 1, row);
}

void	valid_check(t_map *map, t_map *temp_map)
{
	if (temp_map->collected != temp_map->collectible_count)
	{
		free_map(temp_map);
		free_error_exit(map, "Can't pick up all collectibles");
	}
	if (temp_map->exited != 1)
	{
		free_map(temp_map);
		free_error_exit(map, "Exit is unreachable");
	}
}

void	path_check(t_map *map)
{
	t_map	temp_map;

	temp_map = *map;
	temp_map.grid = temp_grid(map);
	flood_fill(&temp_map, map->player.x, map->player.y);
	valid_check(map, &temp_map);
	free_map(&temp_map);
}
