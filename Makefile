# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 17:20:35 by lrecine-          #+#    #+#              #
#    Updated: 2024/10/28 14:26:19 by lrecine-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CC= cc
CFLAGS= -Wall -Wextra -g3
LIBFT= libft/libft.a

HEADERS= -I includes/ -I libft/
# HEADERS= includes/ libft/

SRC= ft_printf.c ft_printf_utils.c

OBJ= $(SRC:%.c=%.o)

%.o: &.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ libft/libft.a

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re:    clean all

PHONY: all, clean, fclean, re