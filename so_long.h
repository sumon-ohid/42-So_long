/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:12:47 by msumon            #+#    #+#             */
/*   Updated: 2023/11/17 22:35:38 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <math.h>
//# include <mlx.h>
# include "./mlx_MacOS/mlx.h"
# include <stdio.h>

#define WIN_WIDTH 1087
#define WIN_HEIGHT 255
#define MAP_HEIGHT 9
#define CELL_SIZE 32
#define KEY_W 13 //119
#define KEY_A 0   //97
#define KEY_S 1 //115
#define KEY_D 2 //100
#define KEY_ESC 53 //65307
#define COIN 5
#define MAP_WIDTH 32

typedef struct s_img
{
    void	*img;
    char	*addr;
    int		width;
    int		height;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_img;

typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    char    **map;
    t_img   bg_img;
    t_img   wall_img;
    t_img   coin_img;
    t_img   mario_img;
    t_img   exit_img;
}   t_data;

void	draw_elements(t_data *data, t_img *wall_img, t_img *coin_img, t_img *mario_img, t_img *exit_img, char **map);
char	**load_map(void);
void	draw_background(t_data *data, t_img *bg_img);
void 	free_map(char **map);
void    do_the_move(int keycode, t_data *data, t_img *wall_img, t_img *coin_img, t_img *mario_img, t_img *exit_img, char **map);
void    get_current_position(char **map, int *x, int *y);
t_img   load_image(void *mlx, char *file);
int     key_hook(int keycode, t_data *data);

#endif