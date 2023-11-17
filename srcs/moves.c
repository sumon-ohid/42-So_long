/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:56:21 by msumon            #+#    #+#             */
/*   Updated: 2023/11/17 23:02:47 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void get_current_position(char **map, int *x, int *y)
{
    int i;
    int j;

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

void do_the_move(int keycode, t_data *data, t_img *wall_img, t_img *coin_img, t_img *mario_img, t_img *exit_img, char **map)
{
    int x;
    int y;
    
    // need to count the number of moves
        
    get_current_position(map, &x, &y);

    if (keycode == KEY_W)
    {
        if (map[y - 1][x] != '1')
        {
            map[y][x] = '0';
            map[y - 1][x] = 'P';
        }
    }
    else if (keycode == KEY_A)
    {
        if (map[y][x - 1] != '1')
        {
            map[y][x] = '0';
            map[y][x - 1] = 'P';
        }
    }
    else if (keycode == KEY_S)
    {
        if (map[y + 1][x] != '1')
        {
            map[y][x] = '0';
            map[y + 1][x] = 'P';
        }
    }
    else if (keycode == KEY_D)
    {
        if (map[y][x + 1] != '1')
        {
            map[y][x] = '0';
            map[y][x + 1] = 'P';
        }
    }
    // After making a move, redraw the map:
    draw_elements(data, wall_img, coin_img, mario_img, exit_img, map);
}
