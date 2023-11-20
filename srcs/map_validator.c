/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:41:12 by msumon            #+#    #+#             */
/*   Updated: 2023/11/20 20:42:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_map(char **map)
{
	if (!contains_exit(map) || !contains_collectible(map)
		|| !contains_start(map))
		return (0);
	if (has_duplicate_characters(map))
		return (0);
	if (!is_rectangular(map))
		return (0);
	if (!is_closed(map))
		return (0);
	if (!has_valid_path(map))
		return (0);
	return (1);
}

int	contains_exit(char **map)
{
	return (1);
}

int	contains_collectible(char **map)
{
	return (1);
}

int	contains_start(char **map)
{
	return (1);
}

int	has_duplicate_characters(char **map)
{
	return (0);
}

int	is_rectangular(char **map)
{
	return (1);
}

int	is_closed(char **map)
{
	return (1);
}

int	has_valid_path(char **map)
{
	return (1);
}