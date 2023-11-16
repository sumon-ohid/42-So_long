/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:35:27 by msumon            #+#    #+#             */
/*   Updated: 2023/11/16 23:57:45 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t main(int32_t argc, char **argv)
{
    t_imgdata   data;
    int32_t     fd;

    ft_bzero(&data, sizeof(t_imgdata));
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
            ft_printf("Error\nInvalid file\n");
        if (!check_ext(argv[1], ".ber"))
            return (EXIT_FAILURE);
		if (!(input_handler(fd, &data, &data.line)))
			return (EXIT_FAILURE);
    }
    else if (argc > 2)
        ft_printf("Error\nToo many arguments\n");
    else
        ft_printf("Error\nNot enough arguments\n");
    if (!graphics(&data, &data.line));
        free_2d(data.map);
    return (0);
}