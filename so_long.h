/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:12:47 by msumon            #+#    #+#             */
/*   Updated: 2023/11/24 14:20:30 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define CELL_SIZE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define COIN 5

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		coins;
	int		coins_collected;
	int		moves;
	int		map_height;
	int		map_width;
	char	**map;
	char	*map_path;
	char	*wall_path;
	char	*bg_path;
	char	*coin_path;
	char	*player_path;
	char	*exit_path;
	t_img	bg_img;
	t_img	wall_img;
	t_img	coin_img;
	t_img	player_img;
	t_img	exit_img;
}			t_data;

typedef struct s_fill
{
	t_data	*data;
	int		x;
	int		y;
	int		**visited;
	int		*collected;
}			t_fill;

void		draw_elements(t_data *data);
char		**load_map(char *map_path);
void		free_map(char **map);
void		do_the_move(int keycode, t_data *data);
void		get_current_position(char **map, int *x, int *y);
t_img		load_image(void *mlx, char *file);
int			key_hook(int keycode, t_data *data);
void		quit_game(t_data *data);
void		draw_game(t_data *data);
void		set_event(t_data *data);
void		load_resources(t_data *data);
void		print_error_and_exit(const char *error_message);
int			height_count(char **map);
void		so_long_welcome(void);
int			ft_strlen_sl(char *str);
void		initialize_mlx(t_data *data);
int			close_window(void *param);
int			map_height(char *str);
int			map_width(char *map_path);
int			is_valid_map(t_data *data);
int			is_rectangular(t_data *data);
int			has_wall_around(t_data *data);
int			has_valid_char(t_data *data);
int			valid_path_check(t_data *data);
void		bonus_draw_text(t_data *data);
void		free_2d_array(int **array, int height);

#endif
