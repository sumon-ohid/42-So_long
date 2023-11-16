/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:35:20 by msumon            #+#    #+#             */
/*   Updated: 2023/11/16 23:41:56 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "helper/super_header.h"
# include <stdint.h>
# include <mlx.h>

typedef struct line
{
	ssize_t	count;
	ssize_t	size;
}	t_line;

typedef struct image_data
{
    t_line			line;
    char			**map;
}   t_imgdata;

#endif