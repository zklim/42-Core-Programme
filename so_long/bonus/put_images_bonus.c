/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:08:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 15:15:28 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_direction(t_map *map, int col, int row)
{
	if (map->grid[row][col] == ENEMY_UP)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.e_back.img[map->e_frame], col * TILESIZE_X, row
			* TILESIZE_X);
	else if (map->grid[row][col] == ENEMY_DOWN)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.e_front.img[map->e_frame], col * TILESIZE_X, row
			* TILESIZE_X);
	else if (map->grid[row][col] == ENEMY_LEFT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.e_left.img[map->e_frame], col * TILESIZE_X, row
			* TILESIZE_X);
	else if (map->grid[row][col] == ENEMY_RIGHT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.e_right.img[map->e_frame], col * TILESIZE_X, row
			* TILESIZE_X);
}

void	images_to_window(t_map *map, int col, int row)
{
	if (map->grid[row][col] == WALL)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->graphic.wall.img,
			col * TILESIZE_X, row * TILESIZE_Y);
	else if (map->grid[row][col] == EXIT)
	{
		if (map->exit_opened && !map->exited)
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->graphic.exit_opened.img, col * TILESIZE_X, row
				* TILESIZE_Y);
		else
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->graphic.exit_closed.img, col * TILESIZE_X, row
				* TILESIZE_Y);
	}
	else if (map->grid[row][col] == COLLECTIBLE)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.collectibles.img, col * TILESIZE_X, row
			* TILESIZE_Y);
	enemy_direction(map, col, row);
}

static void	line_too_long(t_map *map)
{
	if (map->exited)
		mlx_string_put(map->mlx, map->mlx_win, (map->columns - 4)
			* TILESIZE_X / 2, (map->rows - 1) * TILESIZE_Y / 2,
			0x0000FF00, "You Finished the Game!");
	else if (map->player_dead)
		mlx_string_put(map->mlx, map->mlx_win, (map->columns - 1)
			* TILESIZE_X / 2, (map->rows - 1) * TILESIZE_Y / 2,
			0x00FF0000, "You Dead!");
}

void	put_images(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->graphic.background.img, col * TILESIZE_X, row
				* TILESIZE_Y);
			images_to_window(map, col, row);
			col++;
		}
		row++;
	}
	line_too_long(map);
}
