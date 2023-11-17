/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:19:18 by msumon            #+#    #+#             */
/*   Updated: 2023/11/17 16:04:13 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *param)
{
    t_data *data = (t_data *)param;

    if (keycode == 65307) // 65307 is the keycode for the Esc key
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(EXIT_SUCCESS);
    }
    return (0);
}

void	draw_background(t_data *data, t_img *bg_img)
{
    mlx_put_image_to_window(data->mlx, data->mlx_win, bg_img->img, 0, 0);
}

int	main(void)
{
    void	*mlx;
    void	*mlx_win;
    t_img	wall_img;
    t_img	bg_img;
    t_data	data;
    char	*wall_path = "./files/wall.xpm";
    char	*bg_path = "./files/bg.xpm";
    char	**map;
    
    map = load_map();
    if (!map)
    {
        ft_printf("Invalid map\n");
        free_map(map);
        exit(EXIT_FAILURE);
    }

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "So_long");

    if (!(wall_img.img = mlx_xpm_file_to_image(mlx, wall_path, &wall_img.width, &wall_img.height)))
    {
        ft_printf("Error loading wall texture\n");
        free_map(map);
        exit(EXIT_FAILURE);
    }

    if (!(bg_img.img = mlx_xpm_file_to_image(mlx, bg_path, &bg_img.width, &bg_img.height)))
    {
        ft_printf("Error loading background texture\n");
        free_map(map);
        exit(EXIT_FAILURE);
    }

    wall_img.addr = mlx_get_data_addr(wall_img.img, &wall_img.bits_per_pixel, &wall_img.line_length, &wall_img.endian);
    bg_img.addr = mlx_get_data_addr(bg_img.img, &bg_img.bits_per_pixel, &bg_img.line_length, &bg_img.endian);

    data.mlx = mlx;
    data.mlx_win = mlx_win;
    
    draw_background(&data, &bg_img);
    draw_walls(&data, &wall_img, map);

    mlx_key_hook(mlx_win, key_hook, &data);
    mlx_loop(mlx);

    free_map(map);

    return (0);
}
