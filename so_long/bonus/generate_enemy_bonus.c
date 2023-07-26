/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:23:15 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 16:35:06 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	scale_with_map(t_map *map)
{
	int	enemy_num;
	int	scale;

	scale = map->rows * map->columns / map->collectible_count;
	enemy_num = (scale % 13) + 1;
	return (enemy_num);
}

int	random_in_range(t_map *map, int max, int seed)
{
	int	seed2;
	int	rand;

	seed2 = (seed * map->rows * map->columns / map->collectible_count)
		+ map->player.x + map->player.y - map->exit.x - map->exit.y + seed;
	rand = seed2 % max + 1;
	return (rand);
}

void	set_enemy_pos(t_map *map, int seed, int tries)
{
	int	x;
	int	y;

	if (!tries)
		return ;
	x = random_in_range(map, map->columns - 1, seed);
	y = random_in_range(map, map->rows - 1, seed);
	if (map->grid[y][x] != EMPTY)
		set_enemy_pos(map, seed + 1, --tries);
	else
		map->grid[y][x] = ENEMY_DOWN;
}

void	generate_enemy(t_map *map)
{
	int	enemy_num;

	enemy_num = scale_with_map(map);
	while (enemy_num)
	{
		set_enemy_pos(map, 1, 10);
		enemy_num--;
	}
}
