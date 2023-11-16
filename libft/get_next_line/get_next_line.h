/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:57:52 by sumon             #+#    #+#             */
/*   Updated: 2023/11/16 21:54:23 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	clean_line(char *buffer);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(char *s);
#endif