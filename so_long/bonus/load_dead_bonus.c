/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dead_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:26:31 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 15:04:54 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_dead(t_map *map)
{
	t_range	range;

	range.start = 0;
	range.end = 4;
	load_sprite(map, &map->graphic.d_front, range, DEAD_FRONT_PATH);
	load_sprite(map, &map->graphic.d_back, range, DEAD_BACK_PATH);
	load_sprite(map, &map->graphic.d_left, range, DEAD_LEFT_PATH);
	load_sprite(map, &map->graphic.d_right, range, DEAD_RIGHT_PATH);
}
