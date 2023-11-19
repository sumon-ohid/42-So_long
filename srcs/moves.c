/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:56:21 by msumon            #+#    #+#             */
/*   Updated: 2023/11/19 20:13:00 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_current_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i <= MAP_HEIGHT)
	{
		j = 0;
		while (j <= MAP_WIDTH)
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

// void	ft_move(char map, )
// {
// 	if (map[y - 1][x] != '1')
// 	{
// 		if (map[y - 1][x] == 'C') // If the next position contains a coin
// 		{
// 			data->coins_collected++; // Increment the coins_collected counter
// 			map[y - 1][x] = '0';     // Remove the coin from the map
// 		}
// 		else if (map[y - 1][x] == 'E') // If the next position is an exit
// 		{
// 			quit_game(data); // Quit the game and clean up resources
// 			return ;
// 		}
// 		else if (map[y - 1][x] == 'M') // If the next position contains an enemy
// 		{
// 			// Handle collision with enemy
// 			// This could involve losing a life, ending the game, etc.
// 		}
// 		map[y][x] = '0';
// 		map[y - 1][x] = 'P';
// 		data->moves++;
// 	}
// }

void	do_the_move(int keycode, t_data *data, t_img *wall_img, t_img *coin_img,
		t_img *mario_img, t_img *exit_img, char **map)
{
	int	x;
	int	y;

	get_current_position(map, &x, &y);
	if (keycode == KEY_W)
	{
		if (map[y - 1][x] != '1')
		{
            if (map[y - 1][x] == 'E')
			{
				quit_game(data);
				return ;
			}
			map[y][x] = '0';
			map[y - 1][x] = 'P';
			data->moves++;
		}
	}
	else if (keycode == KEY_A)
	{
		if (map[y][x - 1] != '1')
		{
            if (map[y][x - 1] == 'E')
			{
				quit_game(data);
				return ;
			}
			map[y][x] = '0';
			map[y][x - 1] = 'P';
			data->moves++;
		}
	}
	else if (keycode == KEY_S)
	{
		if (map[y + 1][x] != '1')
		{
            if (map[y + 1][x] == 'E')
			{
				quit_game(data);
				return ;
			}
			map[y][x] = '0';
			map[y + 1][x] = 'P';
			data->moves++;
		}
	}
	else if (keycode == KEY_D)
	{
		if (map[y][x + 1] != '1')
		{
            if (map[y][x + 1] == 'E')
			{
				quit_game(data);
				return ;
			}
			map[y][x] = '0';
			map[y][x + 1] = 'P';
			data->moves++;
		}
	}
	ft_printf("Moves: %d\n", data->moves);
	draw_elements(data, wall_img, coin_img, mario_img, exit_img, map);
}

void	quit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	printf("You have reached the exit. Game finished.\n");
	exit(0);
}