/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:41:12 by msumon            #+#    #+#             */
/*   Updated: 2023/11/23 11:15:38 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_valid_map(t_data **map)
{
	if (!contains_exit(map) || !contains_collectible(map)
		|| !contains_start(map))
		return (0);
	if (!is_rectangular(map))
		return (0);
	if (!is_closed(map))
		return (0);
	return (1);
}

int	contains_exit(char **map)
{
	int i;
	int j;
	int count;

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
	if (count > 1)
		return (0);
	return (1);
}

int	contains_collectible(char **map)
{
	int i;
	int j;
	int count;

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
	int i;
	int j;
	int count;

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
	if (count > 1)
		return (0);
	return (1);
}

int	is_rectangular(char **map)
{
	int i;
	int count;
	int count1;

	i = 0;
	count = 0;
	count1 = 0;
	while (map[i])
	{
		count = ft_strlen_sl(map[i]);
		count1 = ft_strlen_sl(map[i + 1]);
		if (count != count1)
			return (0);
		i++;
	}
	return (1);
}

int	is_closed(char **map)
{
	return (1);
}
