/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:19:18 by msumon            #+#    #+#             */
/*   Updated: 2023/11/21 19:35:31 by msumon           ###   ########.fr       */
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
		do_the_move(keycode, data);
	}
	return (0);
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

int	main(int argc, char **argv)
{
	t_data	data;

	data.moves = 0;
	data.wall_path = "./files/wall.xpm";
	data.bg_path = "./files/bg.xpm";
	data.coin_path = "./files/coin.xpm";
	data.player_path = "./files/mushroom.xpm";
	data.exit_path = "./files/exit.xpm";
	if (argc != 2)
		print_error_and_exit("Invalid Argument");
	initialize_mlx(&data);
	load_resources(&data, argv[1]);
	draw_game(&data);
	set_event(&data);
	return (0);
}
