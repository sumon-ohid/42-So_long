/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:55:35 by msumon            #+#    #+#             */
/*   Updated: 2023/11/24 09:43:47 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_data *data, int x, int y, int **visited, int *collected)
{
	if (x < 0 || y < 0 || x >= data->map_height || y >= data->map_width
		|| data->map[x][y] == '1' || visited[x][y])
		return ;
	visited[x][y] = 1;
	if (data->map[x][y] == 'C')
		(*collected)++;
	flood_fill(data, x - 1, y, visited, collected);
	flood_fill(data, x + 1, y, visited, collected);
	flood_fill(data, x, y - 1, visited, collected);
	flood_fill(data, x, y + 1, visited, collected);
}

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

void	free_2d_array(int **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	initialize_data(t_data *data, int *start, int *end,
		int *total_collectibles)
{
	int	i;
	int	j;

	i = 0;
	*total_collectibles = 0;
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
			{
				(*total_collectibles)++;
			}
			j++;
		}
		i++;
	}
}

int	valid_path_check(t_data *data)
{
	int	**visited;
	int	start[2];
	int	end[2];
	int	total_collectibles;
	int	collected;
	int	result;

	collected = 0;
	visited = create_2d_array(data->map_height, data->map_width);
	initialize_data(data, start, end, &total_collectibles);
	flood_fill(data, start[0], start[1], visited, &collected);
	result = visited[end[0]][end[1]] && collected == total_collectibles;
	free_2d_array(visited, data->map_height);
	return (result);
}
