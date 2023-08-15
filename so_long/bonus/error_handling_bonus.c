/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:44:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 16:18:34 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error_exit(char *msg)
{
	ft_printf("%sError\n%s\n%s", RED, msg, NONE);
	exit(1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	free_sprites(t_map *map)
{
	free(map->graphic.front.img);
	free(map->graphic.back.img);
	free(map->graphic.left.img);
	free(map->graphic.right.img);
	free(map->graphic.e_front.img);
	free(map->graphic.e_back.img);
	free(map->graphic.e_left.img);
	free(map->graphic.e_right.img);
	free(map->graphic.d_front.img);
	free(map->graphic.d_back.img);
	free(map->graphic.d_left.img);
	free(map->graphic.d_right.img);
}

void	free_error_exit(t_map *map, char *msg)
{
	if (msg)
		ft_printf("%sError\n%s\n%s", RED, msg, NONE);
	free_map(map);
	exit(0);
}
