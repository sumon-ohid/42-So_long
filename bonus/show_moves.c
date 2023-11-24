/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:11:55 by msumon            #+#    #+#             */
/*   Updated: 2023/11/24 11:31:05 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bonus_draw_text(t_data *data)
{
	int		x;
	int		y;
	int		color;
	char	*moves;
	char	*text;

	x = 10;
	y = 20;
	color = 0x000000;
	moves = ft_itoa(data->moves);
	text = ft_strjoin("MOVES : ", moves);
	mlx_string_put(data->mlx, data->mlx_win, x, y, color, text);
}
