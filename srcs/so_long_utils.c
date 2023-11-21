/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:40:10 by msumon            #+#    #+#             */
/*   Updated: 2023/11/21 06:52:00 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_event(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, key_hook, data);
    mlx_loop(data->mlx);
    free_map(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
}
void	print_error_and_exit(const char *error_message)
{
	ft_printf("Error: %s\n", error_message);
	exit(EXIT_FAILURE);
}
