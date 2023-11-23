/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:11:49 by msumon            #+#    #+#             */
/*   Updated: 2023/11/23 12:03:00 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_height(char *str)
{
	int	fd;
	int	height;

	height = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("Error opening map.");
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	map_width(char *map_path)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("Error opening map.");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	width = ft_strlen_sl(line) - 1;
	free(line);
	close(fd);
	return (width);
}

char	**load_map(char *map_path)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;
	int		height;

	height = map_height(map_path);
	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("Error opening map.");
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		print_error_and_exit("Error allocating memory for map");
	line = get_next_line(fd);
	while (i < height && line != NULL)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

// char	**load_map(void)
// {
//     char	**map;
//     int		i;

//     i = 0;
//     map = (char **)malloc(sizeof(char *) * (MAP_HEIGHT + 1));

//     if (!map)
//     {
//         ft_printf("Error: Failed to allocate memory for map\n");
//         return (NULL);
//     }

//     map[i++] = ft_strdup("1111111111111111111111111111111111");
//     map[i++] = ft_strdup("100000000000000C00000C000E00000001");
//     map[i++] = ft_strdup("1010010100100000101001000000010101");
//     map[i++] = ft_strdup("1010010010101010001001000000010101");
//     map[i++] = ft_strdup("1P0000000C00C0000000000000000000C1");
//     map[i++] = ft_strdup("1111111111111111111111111111111111");
//     map[i++] = ft_strdup("1111111111111111111111111111111111");
//     map[i++] = ft_strdup("1111111111111111111111111111111111");
//     map[i] = NULL;

//     return (map);
// }
