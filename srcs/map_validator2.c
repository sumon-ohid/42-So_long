/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:55:35 by msumon            #+#    #+#             */
/*   Updated: 2023/11/24 12:37:15 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**create_2d_array(int height, int width)
{
	int	i;
	int	**array;

	i = 0;
	array = malloc(height * sizeof(int *));
	if (!array)
		print_error_and_exit("Array malloc failed.");
	while (i < height)
	{
		array[i] = malloc(width * sizeof(int));
		if (!array[i])
			print_error_and_exit("Each Array malloc failed.");
		ft_memset(array[i], 0, width * sizeof(int));
		i++;
	}
	return (array);
}

void	initialize_data(t_data *data, int *start, int *end,
		int *total_collectibles)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'P')
			{
				start[0] = i;
				start[1] = j;
			}
			else if (data->map[i][j] == 'E')
			{
				end[0] = i;
				end[1] = j;
			}
			else if (data->map[i][j] == 'C')
				(*total_collectibles)++;
			j++;
		}
		i++;
	}
}

void	valid_path_check_helper(t_fill params)
{
	int	x;
	int	y;

	x = params.x;
	y = params.y;
	if (x < 0 || y < 0 || x >= params.data->map_height
		|| y >= params.data->map_width || params.data->map[x][y] == '1'
		|| params.visited[x][y])
		return ;
	params.visited[x][y] = 1;
	if (params.data->map[x][y] == 'C')
		(*params.collected)++;
	valid_path_check_helper((t_fill){params.data, x - 1, y, params.visited,
		params.collected});
	valid_path_check_helper((t_fill){params.data, x + 1, y, params.visited,
		params.collected});
	valid_path_check_helper((t_fill){params.data, x, y - 1, params.visited,
		params.collected});
	valid_path_check_helper((t_fill){params.data, x, y + 1, params.visited,
		params.collected});
}

int	valid_path_check(t_data *data)
{
	int		**visited;
	t_fill	params;
	int		start[2];
	int		end[2];
	int		result;

	result = 0;
	data->coins = 0;
	visited = create_2d_array(data->map_height, data->map_width);
	initialize_data(data, start, end, &data->coins);
	params = (t_fill){data, start[0], start[1], visited, &(int){0}};
	valid_path_check_helper(params);
	if (*params.collected == data->coins)
		result = visited[end[0]][end[1]];
	free_2d_array(visited, data->map_height);
	return (result);
}
