# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msumon <msumon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 09:03:46 by msumon            #+#    #+#              #
#    Updated: 2023/10/06 08:39:02 by msumon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_print_char.c ft_print_digit.c ft_print_digit_cap.c \
		ft_print_str.c ft_print_pointer.c ft_printf.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re