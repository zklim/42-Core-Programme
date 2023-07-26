/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:44:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/21 21:05:37 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_error_exit(t_map *map, char *msg)
{
	if (msg)
		ft_printf("%sError\n%s\n%s", RED, msg, NONE);
	free_map(map);
	exit(0);
}
