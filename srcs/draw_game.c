/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:41:27 by msumon            #+#    #+#             */
/*   Updated: 2023/11/23 12:06:22 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_game(t_data *data)
{
	draw_elements(data);
	so_long_welcome();
}

void	load_resources(t_data *data)
{
	data->wall_img = load_image(data->mlx, data->wall_path);
	data->bg_img = load_image(data->mlx, data->bg_path);
	data->coin_img = load_image(data->mlx, data->coin_path);
	data->player_img = load_image(data->mlx, data->player_path);
	data->exit_img = load_image(data->mlx, data->exit_path);
	if (!data->wall_img.img || !data->bg_img.img || !data->coin_img.img
		|| !data->player_img.img || !data->exit_img.img)
	{
		print_error_and_exit("Failed to load textures");
	}
}

t_img	load_image(void *mlx, char *file)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, file, &img.width, &img.height);
	if (img.img == NULL)
	{
		print_error_and_exit("Error loading texture");
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}
