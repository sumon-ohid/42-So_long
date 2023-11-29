/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:19:18 by msumon            #+#    #+#             */
/*   Updated: 2023/11/29 09:05:49 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_data *data)
{
	free_map(data->map);
	mlx_destroy_image(data->mlx, data->exit_img.img);
	mlx_destroy_image(data->mlx, data->bg_img.img);
	mlx_destroy_image(data->mlx, data->coin_img.img);
	mlx_destroy_image(data->mlx, data->player_img.img);
	mlx_destroy_image(data->mlx, data->wall_img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_printf("Window closed. Exiting...\n");
	exit(0);
	return (0);
}

void	initialize_mlx(t_data *data)
{
	int	win_height;
	int	win_width;

	win_height = data->map_height * CELL_SIZE;
	win_width = data->map_width * CELL_SIZE;
	data->mlx_win = mlx_new_window(data->mlx, win_width, win_height, "So_long");
	if (!data->mlx_win)
	{
		print_error_and_exit("Failed to create window");
	}
}

void	game_start(t_data *data)
{
	if (is_valid_map(data) == 1)
	{
		initialize_mlx(data);
		load_resources(data);
		draw_game(data);
		set_event(data);
	}
	else
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(data->map);
		print_error_and_exit("Map is not valid !!");
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_error_and_exit("Invalid Argument");
	data.moves = 0;
	data.map_path = argv[1];
	data.wall_path = "./files/wall.xpm";
	data.bg_path = "./files/bg1.xpm";
	data.coin_path = "./files/coin.xpm";
	data.player_path = "./files/mushroom.xpm";
	data.exit_path = "./files/exit.xpm";
	data.map_height = map_height(data.map_path);
	data.map_width = map_width(data.map_path);
	data.map = load_map(data.map_path);
	if (!(data.map))
	{
		free_map(data.map);
		print_error_and_exit("Invalid map");
	}
	data.mlx = mlx_init();
	if (!data.mlx)
		print_error_and_exit("Failed to initialize mlx");
	game_start(&data);
	return (0);
}