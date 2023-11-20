/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:19:18 by msumon            #+#    #+#             */
/*   Updated: 2023/11/20 20:24:07 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		free_map(data->map);
		mlx_destroy_window(data->mlx, data->mlx_win);
		ft_printf("You pressed ESC. Game Exit.\n");
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		do_the_move(keycode, data, &data->wall_img, &data->coin_img,
			&data->player_img, &data->exit_img, data->map);
	}
	return (0);
}

t_img	load_image(void *mlx, char *file)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, file, &img.width, &img.height);
	if (img.img == NULL)
	{
		ft_putstr_fd("Error loading image\n", 2);
		exit(EXIT_FAILURE);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	draw_background(t_data *data, t_img *bg_img)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, bg_img->img, 0, 0);
}

void	print_error_and_exit(const char *error_message)
{
	ft_printf("Error: %s\n", error_message);
	exit(EXIT_FAILURE);
}

void	initialize_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		print_error_and_exit("Failed to initialize mlx");
	}
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "So_long");
	if (!data->mlx_win)
	{
		print_error_and_exit("Failed to create window");
	}
}

void	load_resources(t_data *data, char *map_path, char *wall_path,
		char *bg_path, char *coin_path, char *player_path, char *exit_path)
{
	data->map = load_map(map_path);
	if (!data->map)
	{
		print_error_and_exit("Invalid map");
	}
	data->wall_img = load_image(data->mlx, wall_path);
	data->bg_img = load_image(data->mlx, bg_path);
	data->coin_img = load_image(data->mlx, coin_path);
	data->player_img = load_image(data->mlx, player_path);
	data->exit_img = load_image(data->mlx, exit_path);
	if (!data->wall_img.img || !data->bg_img.img || !data->coin_img.img
		|| !data->player_img.img || !data->exit_img.img)
	{
		print_error_and_exit("Failed to load textures");
	}
}

void	draw_game(t_data *data)
{
	draw_background(data, &data->bg_img);
	draw_elements(data, &data->wall_img, &data->coin_img, &data->player_img,
		&data->exit_img, data->map);
}

void	set_event_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, key_hook, data);
}

void	start_game_loop(t_data *data)
{
	mlx_loop(data->mlx);
}

void	cleanup_resources(t_data *data)
{
	free_map(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*wall_path;
	char	*bg_path;
	char	*coin_path;
	char	*player_path;
	char	*exit_path;

	wall_path = "./files/wall.xpm";
	bg_path = "./files/bg.xpm";
	coin_path = "./files/coin.xpm";
	player_path = "./files/mushroom.xpm";
	exit_path = "./files/exit.xpm";
	if (argc != 2)
		print_error_and_exit("Invalid Argument");
	initialize_mlx(&data);
	load_resources(&data, argv[1], wall_path, bg_path, coin_path, player_path,
		exit_path);
	draw_game(&data);
	set_event_hooks(&data);
	start_game_loop(&data);
	cleanup_resources(&data);
	return (0);
}
