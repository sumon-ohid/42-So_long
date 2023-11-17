/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:12:47 by msumon            #+#    #+#             */
/*   Updated: 2023/11/17 16:58:35 by msumon           ###   ########.fr       */
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

#define WIN_WIDTH 1087
#define WIN_HEIGHT 255
#define MAP_HEIGHT 9
#define CELL_SIZE 32
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307


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
    void	*mlx;
    void	*mlx_win;
}				t_data;

void	draw_walls(t_data *data, t_img *wall_img, t_img *coin_img, t_img *mario_img, t_img *exit_img, char **map);
char	**load_map(void);
void	draw_background(t_data *data, t_img *bg_img);
void 	free_map(char **map);

#endif