/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:26:46 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/25 12:45:41 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_component(t_map *map, int x, int y)
{
	if (map->grid[y][x] == COLLECTIBLE)
	{
		map->collected++;
		map->grid[y][x] = EMPTY;
		if (map->collected == map->collectible_count)
			map->exit_opened = 1;
	}
	else if (map->grid[y][x] == EXIT)
	{
		if (map->exit_opened)
			map->exited = 1;
		else
			return (0);
	}
	else if (map->grid[y][x] == WALL)
		return (0);
	else if (map->grid[y][x] == ENEMY_UP || map->grid[y][x] == ENEMY_DOWN
			|| map->grid[y][x] == ENEMY_LEFT || map->grid[y][x] == ENEMY_RIGHT)
		map->player_dead = 1;
	return (1);
}

void	check_coord(t_map *map, int x, int y)
{
	if (!check_component(map, x, y))
		return ;
	map->grid[map->player.y][map->player.x] = EMPTY;
	if (!map->exited && !map->player_dead)
		map->grid[y][x] = PLAYER;
	map->player.x = x;
	map->player.y = y;
	++map->walk_count;
	map->force_update = 1;
}

void	direction(int keycode, t_map *map)
{
	if (keycode == W || keycode == UP)
	{
		map->player.direction = UP;
		check_coord(map, map->player.x, map->player.y - 1);
	}
	else if (keycode == S || keycode == DOWN)
	{
		map->player.direction = DOWN;
		check_coord(map, map->player.x, map->player.y + 1);
	}
	else if (keycode == A || keycode == LEFT)
	{
		map->player.direction = LEFT;
		check_coord(map, map->player.x - 1, map->player.y);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		map->player.direction = RIGHT;
		check_coord(map, map->player.x + 1, map->player.y);
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC || keycode == Q)
	{
		ft_printf("Window closing\n");
		destroy_images(map);
		mlx_destroy_window(map->mlx, map->mlx_win);
		free_sprites(map);
		free_error_exit(map, 0);
	}
	if (!map->exited && !map->player_dead)
	{
		direction(keycode, map);
		if (map->exited)
			mlx_string_put(map->mlx, map->mlx_win, (map->columns - 10)
				* TILESIZE_X / 2, map->rows * TILESIZE_Y / 2,
				0x00FF0000, "You Finished The Game!");
		else if (map->player_dead)
			mlx_string_put(map->mlx, map->mlx_win, (map->columns - 5)
				* TILESIZE_X / 2, map->rows * TILESIZE_Y / 2,
				0x00FF0000, "You Dead!");
	}
	return (0);
}
