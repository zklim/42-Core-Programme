/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:14:02 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/23 23:20:49 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	destroy_win(t_map *map)
{
	(void)*map;
	ft_printf("Window closing\n");
	destroy_images(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	free_sprites(map);
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
	generate_enemy(map);
	load_images(map);
	put_images(map);
	mlx_key_hook(map->mlx_win, key_hook, &map->mlx);
	mlx_hook(map->mlx_win, 17, 0, destroy_win, map);
	mlx_loop_hook(map->mlx, render, map);
	mlx_loop(map->mlx);
}
