/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:19:18 by msumon            #+#    #+#             */
/*   Updated: 2023/11/18 18:45:01 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_data *data)
{
    if (keycode == KEY_ESC)
    {
        free_map(data->map);
        mlx_destroy_window(data->mlx, data->mlx_win);
        ft_printf("You pressed ESC. Game Exit.\n");
        exit(0);
    }
    else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
    {
        do_the_move(keycode, data, &data->wall_img, &data->coin_img, &data->mario_img, &data->exit_img, data->map);
    }
    return (0);
}

t_img load_image(void *mlx, char *file)
{
    t_img   img;

    img.img = mlx_xpm_file_to_image(mlx, file, &img.width, &img.height);
    if (img.img == NULL)
    {
        ft_putstr_fd("Error loading image\n", 2);
        exit(EXIT_FAILURE);
    }
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    return (img);
}

void	draw_background(t_data *data, t_img *bg_img)
{
    mlx_put_image_to_window(data->mlx, data->mlx_win, bg_img->img, 0, 0);
}

int main(void)
{
    void *mlx;
    void *mlx_win;
    t_img wall_img;
    t_img bg_img;
    t_img coin_img;
    t_img mario_img;
    t_img exit_img;
    t_data data;
    char *wall_path = "./files/wall.xpm";
    char *bg_path = "./files/bg.xpm";
    char *coin_path = "./files/coin.xpm";
    char *mario_path = "./files/mushroom.xpm";
    char *exit_path = "./files/exit.xpm";
    char **map;

    mlx = mlx_init();
    if (!mlx)
    {
        ft_printf("Error initializing mlx\n");
        exit(EXIT_FAILURE);
    }

    mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "So_long");
    if (!mlx_win)
    {
        ft_printf("Error creating window\n");
        exit(EXIT_FAILURE);
    }

    map = load_map();
    if (!map)
    {
        ft_printf("Invalid map\n");
        exit(EXIT_FAILURE);
    }

    data.map = map;
    data.mlx = mlx;
    data.mlx_win = mlx_win;

    wall_img = load_image(mlx, wall_path);
    bg_img = load_image(mlx, bg_path);
    coin_img = load_image(mlx, coin_path);
    mario_img = load_image(mlx, mario_path);
    exit_img = load_image(mlx, exit_path);

    if (!wall_img.img || !bg_img.img || !coin_img.img || !mario_img.img || !exit_img.img)
    {
        ft_printf("Error loading textures\n");
        free_map(map);
        exit(EXIT_FAILURE);
    }

    data.wall_img = wall_img;
    data.bg_img = bg_img;
    data.coin_img = coin_img;
    data.mario_img = mario_img;
    data.exit_img = exit_img;

    draw_background(&data, &bg_img);
    draw_elements(&data, &wall_img, &coin_img, &mario_img, &exit_img, map);

    //mlx_key_hook(mlx_win, key_hook, &data);
    mlx_hook(mlx_win, 2, 1L << 0, key_hook, &data);
    mlx_hook(mlx_win, 17, 1L << 17, key_hook, &data);
    mlx_loop(mlx);
    free_map(map);
    mlx_destroy_window(mlx, mlx_win);

    return (0);
}

