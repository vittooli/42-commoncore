# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: volivier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 13:35:14 by volivier          #+#    #+#              #
#    Updated: 2024/01/13 14:07:25 by volivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror
MAKEFLAGS+= --silent
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

RM = rm -f

.c.o:
	$(CC) $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
	$(NAME)
