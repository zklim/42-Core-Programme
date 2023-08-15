/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:12:35 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/22 10:19:03 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	components_check(t_map *map)
{
	if (map->start_count != 1 || map->exit_count != 1)
		free_error_exit(map, "Start or exit number is not 1");
	if (map->collectible_count < 1)
		free_error_exit(map, "Less than 1 collectibles");
}

void	validate_map(char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	save_as_grid(fd, map);
	close(fd);
	lines_check(map);
	components_check(map);
	path_check(map);
}
