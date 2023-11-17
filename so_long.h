/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:12:47 by msumon            #+#    #+#             */
/*   Updated: 2023/11/17 16:29:43 by msumon           ###   ########.fr       */
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

void	draw_wall(t_data *data, t_img *wall_img, int x, int y);
void	draw_walls(t_data *data, t_img *wall_img, char **map);
char	**load_map(void);
void	draw_background(t_data *data, t_img *bg_img);
void 	free_map(char **map);

#endif