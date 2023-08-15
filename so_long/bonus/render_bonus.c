/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:47:13 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/24 16:37:13 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	direction(t_map *map)
{
	if (map->player.direction == UP)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.back.img[map->frame], map->player.x * TILESIZE_X,
			map->player.y * TILESIZE_Y);
	else if (map->player.direction == DOWN)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.front.img[map->frame], map->player.x * TILESIZE_X,
			map->player.y * TILESIZE_Y);
	else if (map->player.direction == LEFT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.left.img[map->frame], map->player.x * TILESIZE_X,
			map->player.y * TILESIZE_Y);
	else if (map->player.direction == RIGHT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.right.img[map->frame], map->player.x * TILESIZE_X,
			map->player.y * TILESIZE_Y);
}

static void	dead_direction(t_map *map, int i)
{
	if (map->player.direction == UP)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.d_back.img[i], map->player.x * TILESIZE_X,
			map->player.y * TILESIZE_Y);
	else if (map->player.direction == DOWN)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.d_front.img[i], map->player.x * TILESIZE_X,
			map->player.y * TILESIZE_Y);
	else if (map->player.direction == LEFT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.d_left.img[i], map->player.x * TILESIZE_X,
			map->player.y * TILESIZE_Y);
	else if (map->player.direction == RIGHT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->graphic.d_right.img[i], map->player.x * TILESIZE_X,
			map->player.y * TILESIZE_Y);
}

void	put_string(t_map *map)
{
	char	*str;
	char	*res;
	char	*num;

	str = "Walk count: ";
	num = ft_itoa(map->walk_count);
	res = ft_strjoin(str, num);
	free(num);
	mlx_string_put(map->mlx, map->mlx_win, 5, map->rows
		* TILESIZE_Y - 22, 0x00FFFFFF, res);
	free(res);
}

static void	line_too_long(t_map *map, int *dead_counter, int *frame)
{
	if (map->frame == 4)
		map->frame = 0;
	if (map->e_frame == 10)
		map->e_frame = 0;
	if (!mlx_clear_window(map->mlx, map->mlx_win))
		return ;
	put_images(map);
	if (!map->exited && !map->player_dead)
		direction(map);
	else if (map->player_dead && *dead_counter < 4)
	{
		dead_direction(map, *dead_counter);
		*dead_counter = *dead_counter + 1;
	}
	map->frame++;
	map->e_frame++;
	*frame = 0;
	put_string(map);
	map->force_update = 0;
}

int	render(t_map *map)
{
	static int	frame;
	static int	e_frame;
	static int	dead_counter;

	if (dead_counter < 4)
	{
		if (frame == FRAME || map->force_update)
		{
			line_too_long(map, &dead_counter, &frame);
		}
		move_enemy(map, &e_frame);
		e_frame++;
		frame++;
	}
	return (0);
}
