# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volivier <volivier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 19:36:19 by volivier          #+#    #+#              #
#    Updated: 2024/01/27 00:55:24 by volivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
MAKEFLAGS+= --silent
SRCS = ft_numbers.c ft_printf.c ft_putnbr.c ft_put_unsigned.c ft_pointer.c ft_lowhex.c \
ft_uphex.c ft_putchar.c ft_putstr.c ft_len.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

.c.o:
	$(CC) $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: flean all

.PHONY: all clean fclean re .c.o
