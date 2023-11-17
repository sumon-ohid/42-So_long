/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:58:35 by msumon            #+#    #+#             */
/*   Updated: 2023/11/17 16:02:52 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_wall(t_data *data, t_img *wall_img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, wall_img->img, x * CELL_SIZE, y * CELL_SIZE);
}

void	draw_walls(t_data *data, t_img *wall_img, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_wall(data, wall_img, x, y);
			x++;
		}
		y++;
	}
}

void	free_map(char **map)
{
    int i;
    
    if (!map)
        return;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}


