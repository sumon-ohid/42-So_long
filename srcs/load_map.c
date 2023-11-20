/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:11:49 by msumon            #+#    #+#             */
/*   Updated: 2023/11/20 20:27:38 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**load_map(char *str)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening map file\n");
		exit(EXIT_FAILURE);
	}
	map = (char **)malloc(sizeof(char *) * (MAP_HEIGHT + 1));
	if (!map)
	{
		ft_printf("Error allocating memory for map\n");
		exit(EXIT_FAILURE);
	}
	while (i < MAP_HEIGHT && (line != NULL))
	{
		line = get_next_line(fd);
		map[i++] = line;
	}
	close(fd);
	if (line != NULL)
		free(line);
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
