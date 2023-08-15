/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:22:10 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 15:33:12 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_image(t_map *map, t_sprite *sprite, t_range range)
{
	int	i;
	int	size;

	i = 0;
	size = range.end - range.start;
	while (i < size)
	{
		mlx_destroy_image(map->mlx, sprite->img[i]);
		i++;
	}
}

void	destroy_character(t_map *map)
{
	t_range	range;

	range.start = 0;
	range.end = 4;
	destroy_image(map, &map->graphic.front, range);
	destroy_image(map, &map->graphic.back, range);
	destroy_image(map, &map->graphic.left, range);
	destroy_image(map, &map->graphic.right, range);
}

void	destroy_dead(t_map *map)
{
	t_range	range;

	range.start = 0;
	range.end = 4;
	destroy_image(map, &map->graphic.d_front, range);
	destroy_image(map, &map->graphic.d_back, range);
	destroy_image(map, &map->graphic.d_left, range);
	destroy_image(map, &map->graphic.d_right, range);
}

void	destroy_enemy(t_map *map)
{
	t_range	range;

	range.start = 0;
	range.end = 10;
	destroy_image(map, &map->graphic.e_front, range);
	destroy_image(map, &map->graphic.e_back, range);
	destroy_image(map, &map->graphic.e_left, range);
	destroy_image(map, &map->graphic.e_right, range);
}

void	destroy_images(t_map *map)
{
	mlx_destroy_image(map->mlx, map->graphic.background.img);
	mlx_destroy_image(map->mlx, map->graphic.wall.img);
	mlx_destroy_image(map->mlx, map->graphic.exit_closed.img);
	mlx_destroy_image(map->mlx, map->graphic.exit_opened.img);
	mlx_destroy_image(map->mlx, map->graphic.collectibles.img);
	destroy_character(map);
	destroy_dead(map);
	destroy_enemy(map);
}
