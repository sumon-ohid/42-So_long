/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:03:43 by msumon            #+#    #+#             */
/*   Updated: 2023/11/16 21:54:30 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_pointer(void *ptr);
int	print_digit_cap(long n, int base);
int	print_digit(long n, int base);
int	print_str(char *str);
int	print_char(int c);

#endif