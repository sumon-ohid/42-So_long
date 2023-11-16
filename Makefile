# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/11/16 23:12:14 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
LIBFT = ./libft/
GNL = ./get_next_line/
FTPRINTF = ./ft_printf/
MLX = ./mlx/
HEADERS = -I libft -I get_next_line -I ft_printf -I mlx
SRCDIR = ./srcs/
SRCS = $(wildcard $(SRCDIR)*.c)
OBJS = $(SRCS:.c=.o)
LIBS = -L$(MLX) -lmlx -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(FTPRINTF) -lftprintf

# Color codes
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
NC = \033[0m

all: libft gnl ftprintf mlx compile

libft:
    @echo ${Q}${NL}${GREEN}======== libft ========${NC}${Q}
    @$(MAKE) -C $(LIBFT)

gnl:
    @echo ${Q}${NL}${GREEN}======== get_next_line ========${NC}${Q}
    @$(MAKE) -C $(GNL)

ftprintf:
    @echo ${Q}${NL}${GREEN}======== ft_printf ========${NC}${Q}
    @$(MAKE) -C $(FTPRINTF)

mlx:
    @echo ${Q}${NL}${GREEN}======== MiniLibX ========${NC}${Q}
    @$(MAKE) -C $(MLX)

compile: $(OBJS)
    @echo ${Q}${NL}${PURPLE}======== So_long compiling! ========${NC}${Q}
    $(CC) $(CFLAGS) -g $(HEADERS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
    @$(CC) $(CFLAGS) -c $< -o $@

clean:
    @rm -rf $(OBJS)
    @$(MAKE) -C $(LIBFT) clean
    @$(MAKE) -C $(FTPRINTF) clean
    @$(MAKE) -C $(GNL) clean
    @$(MAKE) -C $(MLX) clean

fclean: clean
    @rm -rf $(NAME)
    @$(MAKE) -C $(LIBFT) fclean
    @$(MAKE) -C $(FTPRINTF) fclean
    @$(MAKE) -C $(GNL) fclean
    @$(MAKE) -C $(MLX) fclean

re: fclean all

.PHONY: all libft ftprintf gnl mlx compile clean fclean re
