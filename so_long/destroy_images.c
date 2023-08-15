/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:17:31 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 15:01:28 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_map *map)
{
	mlx_destroy_image(map->mlx, map->graphic.background.img);
	mlx_destroy_image(map->mlx, map->graphic.wall.img);
	mlx_destroy_image(map->mlx, map->graphic.character.img);
	mlx_destroy_image(map->mlx, map->graphic.exit_closed.img);
	mlx_destroy_image(map->mlx, map->graphic.exit_opened.img);
	mlx_destroy_image(map->mlx, map->graphic.collectibles.img);
}
