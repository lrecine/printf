# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 17:20:35 by lrecine-          #+#    #+#              #
#    Updated: 2024/10/28 17:43:24 by lrecine-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CC= cc
CFLAGS= -Wall -Wextra -Werror

HEADER= -I ft_printf.h

SRC= ft_printf.c ft_printf_utils.c

OBJ= $(SRC:%.c=%.o)

%.o: &.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:    clean all

PHONY: all, clean, fclean, re