/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:56:21 by msumon            #+#    #+#             */
/*   Updated: 2023/11/21 07:28:54 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_strlen_sl(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int height_count(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return (i);
}

void	get_current_position(char **map, int *x, int *y)
{
	int	i;
	int	j;
	int map_width;
	int map_height;

	map_height = height_count(map);
	map_width = ft_strlen_sl(map[0]);
	i = 0;
	while (i <= map_height)
	{
		j = 0;
		while (j <= map_width)
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
void move_player(int new_x, int new_y, char **map, t_data *data)
{
    if (map[new_y][new_x] != '1')
    {
        if (map[new_y][new_x] == 'E' && data->coins_collected == data->coins)
        {
            quit_game(data);
            return;
        }
        int current_x, current_y;
        get_current_position(map, &current_x, &current_y);
        map[current_y][current_x] = '0';
        map[new_y][new_x] = 'P';
        data->moves++;
    }
}

void do_the_move(int keycode, t_data *data, t_img *wall_img, t_img *coin_img,
                 t_img *player_img, t_img *exit_img, char **map)
{
    int x, y;
    get_current_position(map, &x, &y);

    if (keycode == KEY_W)
    {
        move_player(x, y - 1, map, data);
    }
    else if (keycode == KEY_A)
    {
        move_player(x - 1, y, map, data);
    }
    else if (keycode == KEY_S)
    {
        move_player(x, y + 1, map, data);
    }
    else if (keycode == KEY_D)
    {
        move_player(x + 1, y, map, data);
    }
    ft_printf("Moves: %d\n", data->moves);
    draw_elements(data, wall_img, coin_img, player_img, exit_img, map);
}


void	quit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	printf("You have reached the exit. Game finished.\n");
	exit(0);
}
