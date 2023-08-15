/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:05:42 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/25 12:45:15 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/ft_printf/include/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define NONE "\033[0m"

# define TILESIZE_X 32
# define TILESIZE_Y 32

# define BACKGROUND_PATH "./textures/Background.xpm"
# define WALL_PATH "./textures/Wall.xpm"
# define EXIT_CLOSED_PATH "./textures/Exit(Closed).xpm"
# define EXIT_OPENED_PATH "./textures/Exit(Opened).xpm"
# define COLLECTIBLES_PATH "./textures/Treasure.xpm"
# define CHARACTER_PATH "./textures/Front1.xpm"

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define W 13
# define S 1
# define A 0
# define D 2
# define Q 12

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
}				t_img;

typedef struct s_graphic
{
	t_img		background;
	t_img		wall;
	t_img		character;
	t_img		exit_closed;
	t_img		exit_opened;
	t_img		collectibles;
}				t_graphic;

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_map
{
	void		*mlx;
	void		*mlx_win;
	char		**grid;
	t_graphic	graphic;
	t_coord		player;
	t_coord		exit;
	int			start_count;
	int			exit_count;
	int			collectible_count;
	int			rows;
	int			columns;
	int			exit_opened;
	int			exited;
	int			collected;
	int			walk_count;
}				t_map;

void			print_error_exit(char *msg);
void			validate_map(char *av, t_map *map);
void			save_as_grid(int fd, t_map *map);
void			initialize_mlx(t_map *map);
void			free_error_exit(t_map *map, char *msg);
void			lines_check(t_map *map);
void			path_check(t_map *map);
int				key_hook(int keycode, t_map *map);
void			free_map(t_map *map);
int				render(t_map *map);
void			destroy_images(t_map *map);

#endif