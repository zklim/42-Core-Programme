/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:14:02 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 15:01:32 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_map *map)
{
	map->graphic.background.img = mlx_xpm_file_to_image(map->mlx,
			BACKGROUND_PATH, &map->graphic.background.width,
			&map->graphic.background.height);
	map->graphic.wall.img = mlx_xpm_file_to_image(map->mlx, WALL_PATH,
			&map->graphic.wall.width, &map->graphic.wall.height);
	map->graphic.exit_closed.img = mlx_xpm_file_to_image(map->mlx,
			EXIT_CLOSED_PATH, &map->graphic.exit_closed.width,
			&map->graphic.exit_closed.height);
	map->graphic.exit_opened.img = mlx_xpm_file_to_image(map->mlx,
			EXIT_OPENED_PATH, &map->graphic.exit_opened.width,
			&map->graphic.exit_opened.height);
	map->graphic.collectibles.img = mlx_xpm_file_to_image(map->mlx,
			COLLECTIBLES_PATH, &map->graphic.collectibles.width,
			&map->graphic.collectibles.height);
	map->graphic.character.img = mlx_xpm_file_to_image(map->mlx,
			CHARACTER_PATH, &map->graphic.character.width,
			&map->graphic.character.height);
}

static void	too_many_lines(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->graphic.background.img, j * TILESIZE_X, i * TILESIZE_Y);
	if (map->grid[i][j] == WALL)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.wall.img, j * TILESIZE_X, i * TILESIZE_Y);
	if (map->grid[i][j] == PLAYER)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.character.img, j * TILESIZE_X, i * TILESIZE_Y);
	if (map->grid[i][j] == EXIT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.exit_closed.img, j * TILESIZE_X, i
			* TILESIZE_Y);
	if (map->grid[i][j] == COLLECTIBLE)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.collectibles.img, j * TILESIZE_X, i
			* TILESIZE_Y);
}

void	put_images(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			too_many_lines(map, i, j);
			j++;
		}
		i++;
	}
}

int	destroy_win(t_map *map)
{
	(void)*map;
	ft_printf("Window closing\n");
	mlx_destroy_window(map->mlx, map->mlx_win);
	free_error_exit(map, 0);
	return (0);
}

void	initialize_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->columns * TILESIZE_X, map->rows
			* TILESIZE_Y, "so_long");
	if (!map->mlx_win)
		key_hook(ESC, map);
	load_images(map);
	put_images(map);
	mlx_key_hook(map->mlx_win, key_hook, &map->mlx);
	mlx_hook(map->mlx_win, 17, 0, destroy_win, map);
	mlx_loop(map->mlx);
}
