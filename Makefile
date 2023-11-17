# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 20:34:16 by sumon             #+#    #+#              #
#    Updated: 2023/11/17 23:27:45 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS 		= so_long.c ./srcs/elements.c ./srcs/load_map.c ./srcs/moves.c
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME		= so_long
LIBFT		= ./libft/
GNL			= ./get_next_line/
FTPRINTF	= ./ft_printf/

# Color codes
GREEN		= $(shell tput -Txterm setaf 2)
BLUE		= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)


libft:
	@echo ${Q}${NL}${GREEN}======== libft ========${NC}${Q}
	@$(MAKE) -C $(LIBFT) all

gnl:
	@echo ${Q}${NL}${GREEN}======== get_next_line ========${NC}${Q}
	@$(MAKE) -C $(GNL) all

ftprintf:
	@echo ${Q}${NL}${GREEN}======== ft_printf ========${NC}${Q}
	@$(MAKE) -C $(FTPRINTF) all

all: libft gnl ftprintf compile

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): libft gnl ftprintf
	@echo ${Q}${NL}${GREEN}======== All Together Compiled! ========${NC}${Q}
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)libft.a $(GNL)gnl.a $(FTPRINTF)libftprintf.a -o $(NAME)

compile: $(NAME)

clean:
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
