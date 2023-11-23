/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:41:12 by msumon            #+#    #+#             */
/*   Updated: 2023/11/23 14:02:16 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	contains_exit(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	contains_collectible(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
		return (0);
	return (1);
}

int	contains_start(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	is_rectangular(char **map)
{
	int	i;
	int	count;

	i = 1;
	count = ft_strlen_sl(map[0]);
	while (map[i])
	{
		if (ft_strlen_sl(map[i]) != count)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_map(t_data *data)
{
	return (contains_exit(data->map) && contains_collectible(data->map)
		&& contains_start(data->map) && is_rectangular(data->map));
}
