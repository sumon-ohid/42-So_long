# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/11/24 08:56:54 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS 		= so_long.c ./srcs/draw_game.c ./srcs/elements.c ./srcs/load_map.c ./srcs/key_moves.c \
				./srcs/so_long_utils.c ./srcs/map_validator.c ./srcs/map_validator1.c \
				./srcs/map_validator2.c
CC			= cc
CFLAGS		= -g -Wall -Werror -Wextra -lmlx -lX11 -lXext -lm #-Lmlx -lmlx -framework OpenGL -framework AppKit 
NAME		= so_long
LIBFT		= ./libft/
GNL			= ./get_next_line/
FTPRINTF	= ./ft_printf/
MLX			= ./minilibx-linux/

# Color codes
GREEN		= $(shell tput -Txterm setaf 2)
BLUE		= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)

mlx:
	@echo ${Q}${NL}${GREEN}======== minilibx ========${NC}${Q}
	@$(MAKE) -C $(MLX) all

libft:
	@echo ${Q}${NL}${GREEN}======== libft ========${NC}${Q}
	@$(MAKE) -C $(LIBFT) all

gnl:
	@echo ${Q}${NL}${GREEN}======== get_next_line ========${NC}${Q}
	@$(MAKE) -C $(GNL) all

ftprintf:
	@echo ${Q}${NL}${GREEN}======== ft_printf ========${NC}${Q}
	@$(MAKE) -C $(FTPRINTF) all

all: mlx libft gnl ftprintf compile

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): libft gnl ftprintf
	@echo ${Q}${NL}${GREEN}======== All Together Compiled! ========${NC}${Q}
	@$(CC) $(CFLAGS) $(OBJS) $(MLX)libmlx.a $(LIBFT)libft.a $(GNL)gnl.a $(FTPRINTF)libftprintf.a -o $(NAME)

compile: $(NAME)

clean:
	@$(MAKE) -C $(MLX) clean
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FTPRINTF) clean
	@$(MAKE) -C $(GNL) clean
	@rm -f $(NAME)
	@echo ${Q}${NC}${BLUE}======== Cleaned! ========${NC}${Q}
		
fclean: clean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	@$(MAKE) -C $(GNL) fclean
	@rm -f $(NAME)
	@echo ${Q}${NC}${BLUE}======== Super Cleaned! ========${NC}${Q}
	
re: fclean all

.PHONY: all libft gnl ftprintf compile clean fclean re
