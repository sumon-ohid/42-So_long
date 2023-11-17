/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:19:18 by msumon            #+#    #+#             */
/*   Updated: 2023/11/17 17:01:46 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *param)
{
    t_data *data = (t_data *)param;

    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(EXIT_SUCCESS);
    }
    else if (keycode == KEY_W)
    {
        
    }
    else if (keycode == KEY_A)
    {
        
    }
    else if (keycode == KEY_S)
    {
        
    }
    else if (keycode == KEY_D)
    {
        
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
    t_img	coin_img;
    t_data	data;
    char	*wall_path = "./files/wall.xpm";
    char	*bg_path = "./files/bg.xpm";
    char	*coin_path = "./files/coin.xpm";
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

    if (!(coin_img.img = mlx_xpm_file_to_image(mlx, coin_path, &coin_img.width, &coin_img.height)))
    {
        ft_printf("Error loading coin texture\n");
        exit(EXIT_FAILURE);
    }

    t_img	mario_img;
    char	*mario_path = "./files/mario.xpm";

    if (!(mario_img.img = mlx_xpm_file_to_image(mlx, mario_path, &mario_img.width, &mario_img.height)))
    {
        ft_printf("Error loading Mario texture\n");
        exit(EXIT_FAILURE);
    }
    
    t_img	exit_img;
    char	*exit_path = "./files/exit.xpm";

    if (!(exit_img.img = mlx_xpm_file_to_image(mlx, exit_path, &exit_img.width, &exit_img.height)))
    {
        ft_printf("Error loading exit texture\n");
        exit(EXIT_FAILURE);
    }

    wall_img.addr = mlx_get_data_addr(wall_img.img, &wall_img.bits_per_pixel, &wall_img.line_length, &wall_img.endian);
    bg_img.addr = mlx_get_data_addr(bg_img.img, &bg_img.bits_per_pixel, &bg_img.line_length, &bg_img.endian);
    coin_img.addr = mlx_get_data_addr(coin_img.img, &coin_img.bits_per_pixel, &coin_img.line_length, &coin_img.endian);
    mario_img.addr = mlx_get_data_addr(mario_img.img, &mario_img.bits_per_pixel, &mario_img.line_length, &mario_img.endian);
    exit_img.addr = mlx_get_data_addr(exit_img.img, &exit_img.bits_per_pixel, &exit_img.line_length, &exit_img.endian);

    data.mlx = mlx;
    data.mlx_win = mlx_win;
    
    draw_background(&data, &bg_img);
    draw_walls(&data, &wall_img, &coin_img, &mario_img, &exit_img, map);    
    mlx_key_hook(mlx_win, key_hook, &data);
    mlx_hook(mlx_win, 2, 1L<<0, key_hook, &data);
    mlx_loop(mlx);

    free_map(map);

    return (0);
}
